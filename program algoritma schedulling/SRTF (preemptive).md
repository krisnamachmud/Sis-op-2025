#include<stdio.h>
#define MAX 9999
struct proc
{
    int no,at,bt,rt,ct,tat,wt;
};
struct proc read(int i)
{
    struct proc p;
    printf("\nProcess No: %d\n",i);
    p.no=i;
    printf("Enter Arrival Time: ");
    scanf("%d",&p.at);
    printf("Enter Burst Time: ");
    scanf("%d",&p.bt);
    p.rt=p.bt;
    return p;
}
int main()
{
    struct proc p[10],temp;
    float avgtat=0,avgwt=0;
    int n,s,remain=0,time;
    printf("<--SRTF Scheduling Algorithm (Preemptive)-->\n");
    printf("Enter Number of Processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        p[i]=read(i+1);
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)    
            if(p[j].at>p[j+1].at)
            {
            temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
            }
    printf("\nProcess\t\tAT\tBT\tCT\tTAT\tWT\n");
    p[9].rt=MAX;
    for(time=0;remain!=n;time++)
    {
        s=9;
        for(int i=0;i<n;i++)
            if(p[i].at<=time&&p[i].rt<p[s].rt&&p[i].rt>0)
                s=i;
        p[s].rt--;
        if(p[s].rt==0)
        {
            remain++;
            p[s].ct=time+1;
            p[s].tat=p[s].ct-p[s].at;
            avgtat+=p[s].tat;
            p[s].wt=p[s].tat-p[s].bt;
            avgwt+=p[s].wt;
            printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",p[s].no,p[s].at,p[s].bt,p[s].ct,p[s].tat,p[s].wt);
        }
    }
    avgtat/=n,avgwt/=n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f",avgtat,avgwt);
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

