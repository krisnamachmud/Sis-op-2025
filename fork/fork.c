#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define N 4 // Ukuran matriks 4x4

int main() {
    // Inisialisasi matriks A dan B
    int A[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    int B[N][N] = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };
    
    // Menciptakan shared memory untuk hasil
    int shmid;
    int (*result)[N]; // Pointer untuk matriks hasil
    key_t key = IPC_PRIVATE;
    
    // Alokasi shared memory untuk menyimpan matriks hasil
    shmid = shmget(key, N * N * sizeof(int), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    
    // Attach shared memory
    result = shmat(shmid, NULL, 0);
    if (result == (int (*)[N]) -1) {
        perror("shmat");
        exit(1);
    }
    
    // Inisialisasi matriks hasil
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
        }
    }
    
    // Membuat proses anak untuk setiap baris matriks
    pid_t pid;
    for (int i = 0; i < N; i++) {
        pid = fork();
        
        if (pid < 0) {
            // Error handling
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // Proses anak - bertanggung jawab untuk 1 baris
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
            exit(0); // Proses anak menyelesaikan tugasnya
        }
    }
    
    // Proses induk - menunggu semua proses anak selesai
    for (int i = 0; i < N; i++) {
        wait(NULL);
    }
    
    // Menampilkan matriks A
    printf("Matriks A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", A[i][j]);
        }
        printf("\n");
    }
    
    // Menampilkan matriks B
    printf("\nMatriks B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", B[i][j]);
        }
        printf("\n");
    }
    
    // Menampilkan hasil perkalian
    printf("\nHasil Perkalian A x B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", result[i][j]);
        }
        printf("\n");
    }
    
    // Detach shared memory
    if (shmdt(result) == -1) {
        perror("shmdt");
        exit(1);
    }
    
    // Hapus shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    
    return 0;
}
