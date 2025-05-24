# SJF Scheduling Algorithm (Non-Preemptive, With Arrival Time)

🚀 **Deskripsi**  
Program ini mengimplementasikan algoritma Shortest Job First (SJF) non-preemptive dengan mempertimbangkan arrival time (waktu kedatangan) menggunakan bahasa C.

---

## 📋 Fitur
- Input arrival time (AT) dan burst time (BT) untuk tiap proses
- Mengurutkan proses berdasarkan waktu kedatangan, kemudian burst time
- Menghitung:
  - Completion Time (CT)
  - Turn Around Time (TAT)
  - Waiting Time (WT)
  - Response Time (RT)
- Menampilkan rata-rata TAT dan WT

---

## 💻 Cara Menjalankan

1️⃣ Compile:
```bash
gcc sjf_with_arrival.c -o sjf
