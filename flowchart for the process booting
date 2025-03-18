# Dokumentasi Proses Booting Komputer
**Tugas Sistem Operasi - Flowchart Proses Booting**

## Pendahuluan
Flowchart ini menggambarkan proses lengkap booting komputer dari keadaan mati hingga siap digunakan. Proses ini dibagi menjadi dua bagian utama yang dihubungkan dengan konektor alfabet (A).

## Bentuk Diagram yang Digunakan
1. **Persegi Panjang dengan Sudut Rounded** - Menunjukkan proses atau tindakan
2. **Belah Ketupat** - Menunjukkan keputusan
3. **Stadion/Capsule** - Menunjukkan terminator (Mulai/Selesai)
4. **Lingkaran** - Menunjukkan konektor antar bagian

## Bagian 1: Inisialisasi Hardware
Dimulai saat komputer dimatikan dan berakhir ketika bootloader dimuat.

1. **Komputer Dimatikan**: Keadaan awal
2. **Menekan Tombol Power**: Pengguna mengaktifkan power supply
3. **Power On Self Test (POST)**:
   - BIOS/UEFI melakukan pengecekan hardware dasar
   - Memeriksa integritas komponen utama
4. **POST Berhasil?**: 
   - Jika Tidak: Menampilkan kode error atau beep code
   - Error harus diperbaiki melalui troubleshooting hardware
5. **BIOS/UEFI Initialization**:
   - Memuat firmware yang diperlukan
   - Menjalankan konfigurasi dasar
6. **Deteksi & Inisialisasi Hardware Dasar**:
   - Mengenali dan mengonfigurasi CPU, RAM, storage
   - Menyiapkan konfigurasi I/O dasar
7. **Scan Boot Sequence**:
   - Memeriksa perangkat boot sesuai urutan prioritas
8. **Bootable Device Ditemukan?**:
   - Jika Tidak: Menampilkan error dan meminta konfigurasi ulang
   - Jika Ya: Melanjutkan proses boot
9. **Load Boot Loader**:
   - Memuat program bootloader (GRUB, Windows Boot Manager, dll)
   - Bootloader berada di sektor boot media penyimpanan

## Bagian 2: Loading OS & User Environment
Dimulai dari memuat kernel OS dan berakhir saat komputer siap digunakan.

1. **Bootloader Memuat Kernel OS**:
   - Memuat kernel ke dalam memori
   - Menyiapkan parameter boot
2. **Kernel Menginisialisasi Sistem**:
   - Mengatur manajemen memori
   - Mempersiapkan kontrol proses
3. **Kernel Memuat Driver Hardware**:
   - Memuat driver untuk storage, display, input, network
   - Mengaktifkan subsistem hardware
4. **Menjalankan Init/systemd (Linux) atau smss.exe (Windows)**:
   - Process pertama yang berjalan (PID 1 pada Linux)
   - Mengontrol startup sistem selanjutnya
5. **Memuat System Services**:
   - Mengaktifkan layanan jaringan, keamanan
   - Memulai layanan latar belakang
6. **Display Manager/Login Screen**:
   - Menampilkan antarmuka login
7. **User Authentication**:
   - Memverifikasi kredensial pengguna
8. **Memuat User Environment**:
   - Memulai desktop environment (GUI) atau shell (CLI)
   - Memuat pengaturan pengguna
9. **Komputer Siap Digunakan**:
   - Sistem operational dan siap menerima input pengguna

## Color Coding
- **Biru** - Proses normal
- **Merah** - Keputusan/decision point
- **Hijau** - Terminator (mulai/selesai)
- **Kuning** - Konektor

## Referensi
- Silberschatz, A., Galvin, P.B., & Gagne, G. (2018). Operating System Concepts.
- Tanenbaum, A.S. (2015). Modern Operating Systems.
