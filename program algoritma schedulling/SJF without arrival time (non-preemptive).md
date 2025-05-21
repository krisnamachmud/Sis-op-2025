#include<stdio.h>
struct proc
{
    int no,bt,ct,tat,wt;
};
struct proc read(int i)
{
    struct proc p;
    printf("\nProcess No: %d\n",i);
    p.no=i;
    printf("Enter Burst Time: ");
    scanf("%d",&p.bt);
    return p;
}
int main()
{
    struct proc p[10],tmp;
    float avgtat=0,avgwt=0;
    int n,ct=0;
    printf("<--SJF Scheduling Algorithm Without Arrival Time (Non-Preemptive)-->\n");
    printf("Enter Number of Processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        p[i]=read(i+1);
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)    
            if(p[j].bt>p[j+1].bt)
            {
				tmp=p[j];
				p[j]=p[j+1];
				p[j+1]=tmp;
            }
    printf("\nProcessNo\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++)
    {
        ct+=p[i].bt;
		p[i].ct=p[i].tat=ct;
		avgtat+=p[i].tat;
        p[i].wt=p[i].tat-p[i].bt;
        avgwt+=p[i].wt;
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",p[i].no,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].wt);
    }
    avgtat/=n,avgwt/=n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f",avgtat,avgwt);
}


# Analisis Program

Kode ini mengimplementasikan algoritma penjadwalan CPU SJF (Shortest Job First) non-preemptive, di mana:

- Program menerima input untuk beberapa proses (waktu burst masing-masing)
- Mengurutkan proses berdasarkan waktu burst (terpendek terlebih dahulu)
- Menghitung waktu penyelesaian (Completion Time / CT), waktu perputaran (Turnaround Time / TAT), dan waktu tunggu (Waiting Time / WT) untuk setiap proses
- Menghitung rata-rata waktu perputaran dan waktu tunggu

## Komponen Utama:

### Struktur Data
Menggunakan `struct proc` untuk menyimpan informasi proses:

- Nomor proses (no)
- Waktu burst (bt)
- Waktu penyelesaian (ct)
- Waktu perputaran (tat)
- Waktu tunggu (wt)

### Pengumpulan Input
Fungsi `read()` digunakan untuk menerima waktu burst dari setiap proses.

### Pengurutan
Mengimplementasikan bubble sort untuk mengurutkan proses berdasarkan waktu burst secara menaik.

### Perhitungan:

- **CT** = Jumlah waktu burst hingga proses saat ini
- **TAT** = CT (karena waktu kedatangan semua proses adalah 0)
- **WT** = TAT - BT

### Output
Menampilkan tabel berisi semua metrik proses dan rata-rata TAT serta WT.

## Alur Algoritma:

1. Dapatkan jumlah proses (`n`)
2. Untuk setiap proses (1 hingga n), baca waktu burst
3. Urutkan proses berdasarkan waktu burst (menggunakan bubble sort)
4. Hitung CT, TAT, dan WT untuk setiap proses secara berurutan
5. Tampilkan detail proses dan nilai rata-rata

---

# Analisis Eksekusi Contoh

Dari tangkapan layar Anda terlihat bahwa:

- 5 proses dimasukkan
- Waktu burst: P1=2, P2=3, P3=4, P4=5, P5=6
- Setelah diurutkan berdasarkan waktu burst, urutan eksekusi menjadi: P1 → P2 → P3 → P4 → P5

### Nilai CT:
2 → 5 → 9 → 14 → 20

### Nilai TAT:
2 → 5 → 9 → 14 → 20 (sama dengan CT karena waktu kedatangan adalah 0)

### Nilai WT:
0 → 2 → 5 → 9 → 14

### Nilai RT:
Sama dengan WT (karena tidak ada preemption)

### Rata-rata yang dihitung:

- **Rata-rata TAT** = 10.00
- **Rata-rata WT** = 6.00

---

# Observasi dan Wawasan

- **Implementasi SJF Non-Preemptive**: Algoritma tidak mempertimbangkan waktu kedatangan proses - diasumsikan semua proses datang pada waktu 0.
- **Efisiensi Penjadwalan**: SJF optimal untuk meminimalkan rata-rata waktu tunggu saat semua proses tiba secara bersamaan.
- **Identitas Proses**: Algoritma mempertahankan nomor proses asli (`p[i].no`) meskipun telah diurutkan, memastikan identifikasi yang benar dalam output.
- **Waktu Respons**: Dalam implementasi ini, RT sama dengan WT karena tidak ada preemption.
- **Struktur Kode**: Menggunakan bubble sort yang sederhana, cocok untuk jumlah proses kecil tetapi tidak efisien untuk dataset besar.
- **Kebenaran Output**: Perhitungan sesuai dengan nilai yang diharapkan untuk algoritma SJF.

Program ini secara benar mengimplementasikan algoritma penjadwalan SJF non-preemptive dan menghasilkan hasil yang akurat berdasarkan input yang diberikan.


