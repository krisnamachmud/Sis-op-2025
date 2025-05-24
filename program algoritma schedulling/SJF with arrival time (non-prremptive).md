
#include <stdio.h>

struct proc {
    int no, at, bt, it, ct, tat, wt;
};

struct proc read(int i) {
    struct proc p;
    printf("\nProcess No: %d\n", i);
    p.no = i;
    printf("Enter Arrival Time: ");
    scanf("%d", &p.at);
    printf("Enter Burst Time: ");
    scanf("%d", &p.bt);
    return p;
}

int main() {
    int n, j, min = 0;
    float avgtat = 0, avgwt = 0;
    struct proc p[10], temp;

    printf("<--SJF Scheduling Algorithm (Non-Preemptive)-->\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        p[i] = read(i + 1);

    // Sort by arrival time
    for (int i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (p[j].at > p[j + 1].at) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }

    // Find first process with shortest burst time if same arrival
    for (j = 1; j < n && p[j].at == p[0].at; j++)
        if (p[j].bt < p[min].bt)
            min = j;

    temp = p[0];
    p[0] = p[min];
    p[min] = temp;

    p[0].it = p[0].at;
    p[0].ct = p[0].it + p[0].bt;

    for (int i = 1; i < n; i++) {
        for (j = i + 1, min = i; j < n && p[j].at <= p[i - 1].ct; j++)
            if (p[j].bt < p[min].bt)
                min = j;

        temp = p[i];
        p[i] = p[min];
        p[min] = temp;

        if (p[i].at <= p[i - 1].ct)
            p[i].it = p[i - 1].ct;
        else
            p[i].it = p[i].at;

        p[i].ct = p[i].it + p[i].bt;
    }

    printf("\nProcess\t\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        avgtat += p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        avgwt += p[i].wt;

        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].no, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].wt);
    }

    avgtat /= n;
    avgwt /= n;
    printf("\nAverage TurnAround Time = %f\n", avgtat);
    printf("Average Waiting Time = %f\n", avgwt);

    return 0;
}

# Analisis Program

Kode ini mengimplementasikan algoritma penjadwalan SJF (Shortest Job First) yang lebih realistis karena mempertimbangkan waktu kedatangan proses. Perbedaan utama dari kode sebelumnya adalah:

## Peningkatan Struktur Data:

- Menambahkan `at` (arrival time / waktu kedatangan)
- Menambahkan `it` (initial time / waktu mulai awal atau waktu mulai respons)

## Kompleksitas Algoritma:

- Pertama-tama mengurutkan proses berdasarkan waktu kedatangan
- Kemudian memilih pekerjaan terpendek yang tersedia pada setiap titik keputusan penjadwalan

---

## Komponen Utama:

### Struktur Proses
`struct proc` kini mencakup:

- Nomor proses (no)
- Waktu kedatangan (at)
- Waktu burst (bt)
- Waktu mulai (it)
- Waktu penyelesaian (ct)
- Waktu perputaran (tat)
- Waktu tunggu (wt)

### Pengumpulan Input
Fungsi `read()` kini menerima waktu kedatangan dan waktu burst untuk setiap proses.

### Logika Penjadwalan:

- Pertama, mengurutkan semua proses berdasarkan waktu kedatangan (menggunakan bubble sort)
- Menangani kasus khusus eksekusi proses pertama
- Untuk proses berikutnya, memilih proses dengan waktu burst terpendek di antara proses yang telah tiba pada waktu penyelesaian proses sebelumnya

---

## Perhitungan:

- **CT** = IT + BT (waktu penyelesaian = waktu mulai + waktu burst)
- **TAT** = CT - AT (waktu perputaran = waktu penyelesaian - waktu kedatangan)
- **WT** = TAT - BT (waktu tunggu = waktu perputaran - waktu burst)

---

## Alur Algoritma:

1. Urutkan proses berdasarkan waktu kedatangan
2. Di antara proses yang tiba bersamaan dengan proses pertama, pilih yang memiliki waktu burst terpendek
3. Untuk setiap posisi berikutnya dalam jadwal:
   - Di antara proses yang telah tiba pada waktu penyelesaian proses sebelumnya, pilih proses dengan waktu burst terpendek
   - Hitung waktu mulai dan waktu penyelesaiannya

---

# Analisis Eksekusi Contoh

Dari tangkapan layar Anda terlihat bahwa:

### 6 proses dimasukkan dengan nilai (AT, BT):

- P1: (0,1)
- P2: (2,3)
- P3: (4,5)
- P4: (6,7)
- P5: (8,9)
- P6: (10,11)

### Setelah dieksekusi:

Proses dijadwalkan dalam urutan: P1 → P2 → P3 → P4 → P5 → P6

| Proses | CT  | TAT | WT | RT |
|--------|-----|-----|----|----|
| P1     | 1   | 1   | 0  | 0  |
| P2     | 5   | 3   | 0  | 0  |
| P3     | 10  | 6   | 1  | 1  |
| P4     | 17  | 11  | 4  | 4  |
| P5     | 26  | 18  | 9  | 9  |
| P6     | 37  | 27  | 16 | 16 |

---

### Rata-rata:

- **Rata-rata TAT** = 11.0
- **Rata-rata WT** = 5.0

---

