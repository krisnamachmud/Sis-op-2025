#include <stdio.h>

struct proc {
    int no, bt, ct, tat, wt;
};

struct proc read(int i) {
    struct proc p;
    printf("\nProcess No: %d\n", i);
    p.no = i;
    printf("Enter Burst Time: ");
    scanf("%d", &p.bt);
    return p;
}

int main() {
    struct proc p[10], tmp;
    float avgtat = 0, avgwt = 0;
    int n, ct = 0;

    printf("<-- SJF Scheduling Algorithm Without Arrival Time (Non-Preemptive) -->\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    // Input burst time
    for (int i = 0; i < n; i++)
        p[i] = read(i + 1);

    // Sort processes by burst time (ascending)
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (p[j].bt > p[j + 1].bt) {
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }

    printf("\nProcessNo\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        ct += p[i].bt;
        p[i].ct = ct;
        p[i].tat = p[i].ct;
        avgtat += p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        avgwt += p[i].wt;

        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",
               p[i].no, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].wt);
    }

    avgtat /= n;
    avgwt /= n;

    printf("\nAverage TurnAround Time = %.2f\n", avgtat);
    printf("Average Waiting Time = %.2f\n", avgwt);

    return 0;
}

# Analisis Program

Kode ini mengimplementasikan algoritma penjadwalan CPU SRTF (Shortest Remaining Time First), di mana:

- Proses dapat dipreempt jika ada proses baru dengan waktu sisa yang lebih pendek
- CPU selalu menjalankan proses dengan waktu eksekusi sisa terpendek
- Algoritma mensimulasikan kemajuan waktu satu per satu (time quantum = 1)

---

## Komponen Utama:

### Struktur Proses yang Ditingkatkan:
`struct proc` mencakup:

- Nomor proses (no)
- Waktu kedatangan (at)
- Waktu burst (bt) – total waktu eksekusi yang dibutuhkan
- Waktu tersisa (rt) – sisa waktu eksekusi
- Waktu penyelesaian (ct)
- Waktu perputaran (tat)
- Waktu tunggu (wt)

### Pengumpulan Input:
Sama seperti sebelumnya, tetapi sekarang menginisialisasi `rt = bt` untuk setiap proses.

### Pengurutan Awal:
Mengurutkan proses berdasarkan waktu kedatangan (menggunakan bubble sort)

---

## Inti Simulasi:

- Menggunakan loop kemajuan waktu yang meningkat satu per satu
- Pada setiap satuan waktu, memilih proses dengan waktu sisa terpendek di antara yang tersedia
- Mengurangi waktu sisa dari proses yang dipilih
- Ketika sebuah proses selesai (`rt = 0`), menghitung metrik-metriknya

---

## Alur Algoritma:

1. Urutkan proses berdasarkan waktu kedatangan
2. Untuk setiap satuan waktu (mulai dari 0):
   - Cari proses dengan waktu sisa terpendek yang telah datang
   - Jalankan proses tersebut selama 1 satuan waktu
   - Jika proses selesai (`rt = 0`), hitung metriknya
3. Lanjutkan hingga semua proses selesai

---

# Analisis Eksekusi Contoh

Dari tangkapan layar Anda terlihat:

### 4 proses dimasukkan dengan nilai (AT, BT):

- P1: (1, 2)
- P2: (3, 4)
- P3: (5, 6)
- P4: (7, 8)

### Jejak eksekusi:

- t=0: Belum ada proses yang tersedia
- t=1: P1 tiba, mulai dieksekusi
- t=2: P1 melanjutkan eksekusi
- t=3: P1 selesai, P2 tiba dan mulai dieksekusi
- t=4–6: P2 melanjutkan eksekusi
- t=7: P2 selesai, P3 dan P4 tersedia, P3 punya waktu sisa lebih pendek (6 vs 8), jadi P3 mulai
- t=8–12: P3 melanjutkan eksekusi
- t=13: P3 selesai, P4 mulai
- t=14–20: P4 melanjutkan eksekusi
- t=21: P4 selesai

---

## Hasil:

| Proses | CT  | TAT | WT |
|--------|-----|-----|----|
| P1     | 3   | 2   | 0  |
| P2     | 7   | 4   | 0  |
| P3     | 13  | 8   | 2  |
| P4     | 21  | 14  | 6  |

---

## Rata-rata:

- **Rata-rata TAT** = 7.0
- **Rata-rata WT** = 2.0

---

