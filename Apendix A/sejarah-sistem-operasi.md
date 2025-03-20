# Sejarah dan Evolusi Sistem Operasi

## Sistem Komputer Didedikasikan

Seiring berjalannya waktu, perangkat lunak dan perangkat keras tambahan dikembangkan.

### Pengembangan Perangkat Keras
- Pembaca kartu
- Printer baris
- Pita magnetik

### Pengembangan Perangkat Lunak
- Assembler
- Loader
- Linker

**Perpustakaan Fungsi Umum:**
- Fungsi umum dapat disalin ke program baru tanpa harus ditulis ulang
- Memberikan kemampuan penggunaan kembali perangkat lunak

### Driver Perangkat

Rutin yang melakukan I/O sangat penting. Setiap perangkat I/O baru memiliki karakteristiknya sendiri, yang membutuhkan pemrograman yang cermat.

**Karakteristik Driver Perangkat:**
- Subrutin khusus yang ditulis untuk setiap perangkat I/O
- Menangani buffer, flag, register, bit kontrol, dan bit status untuk perangkat tertentu
- Setiap jenis perangkat memiliki driver sendiri
- Memudahkan tugas seperti membaca karakter dari pembaca pita kertas

### Kompiler dan Bahasa Pemrograman

Kompiler untuk FORTRAN, COBOL, dan bahasa lainnya muncul, membuat tugas pemrograman jauh lebih mudah tetapi operasi komputer menjadi lebih kompleks.

**Proses Menjalankan Program FORTRAN:**
1. Memuat kompiler FORTRAN ke dalam komputer dari pita magnetik
2. Program dibaca melalui pembaca kartu dan ditulis ke pita lain
3. Kompiler FORTRAN menghasilkan output dalam bahasa assembly
4. Output assembly harus di-assemble menggunakan assembler dari pita lain
5. Output assembler di-link ke rutin perpustakaan pendukung
6. Bentuk objek biner dari program siap dieksekusi
7. Program dimuat ke memori dan di-debug dari konsol

## Sistem Komputer Bersama

Seiring kompleksitas komputer meningkat, muncul kebutuhan untuk solusi baru dalam pengoperasian komputer.

### Operator Profesional

Solusi pertama adalah mempekerjakan operator komputer profesional:

**Manfaat:**
- Programmer tidak lagi mengoperasikan mesin
- Begitu satu pekerjaan selesai, operator dapat memulai pekerjaan berikutnya langsung
- Operator memiliki lebih banyak pengalaman dalam memasang pita, mengurangi waktu setup
- Programmer cukup menyediakan kartu/pita yang diperlukan dan deskripsi singkat pekerjaan

**Keterbatasan:**
- Operator tidak dapat men-debug program yang salah di konsol
- Dalam kasus kesalahan program, dump memori dan register diambil
- Programmer harus men-debug dari dump tersebut
- Membuang memori dan register memungkinkan operator melanjutkan pekerjaan berikutnya
- Programmer menghadapi masalah debugging yang lebih sulit

### Sistem Batch

Solusi kedua adalah mengelompokkan pekerjaan dengan kebutuhan serupa untuk mengurangi waktu setup:

**Contoh:**
- Jika operator menerima: pekerjaan FORTRAN → pekerjaan COBOL → pekerjaan FORTRAN
- Jika dijalankan dalam urutan tersebut:
  - Menyiapkan FORTRAN → menyiapkan COBOL → menyiapkan FORTRAN lagi
- Jika dua program FORTRAN dijalankan sebagai satu batch:
  - Hanya perlu menyiapkan FORTRAN sekali
  - Menghemat waktu operator

## Sistem Operasi Bersejarah

### Sistem Atlas

Sistem operasi Atlas dirancang di Universitas Manchester di Inggris pada akhir 1950-an dan awal 1960-an.

#### Fitur Utama Atlas
- Banyak fitur dasarnya yang dianggap baru pada masanya kini menjadi standar sistem operasi modern
- Driver perangkat adalah bagian utama dari sistem
- Panggilan sistem ditambahkan oleh serangkaian instruksi khusus yang disebut kode tambahan
- Sistem operasi batch dengan spooling
- Spooling memungkinkan sistem menjadwalkan pekerjaan sesuai ketersediaan perangkat periferal:
  - Unit pita magnetik
  - Pembaca pita kertas
  - Pukulan pita kertas
  - Printer baris
  - Pembaca kartu
  - Pukulan kartu

#### Manajemen Memori Atlas
- Fitur paling menonjol dari Atlas adalah manajemen memorinya
- Memori inti pada saat itu baru dan mahal
- Banyak komputer, seperti IBM 650, menggunakan drum untuk memori utama
- Sistem Atlas menggunakan:
  - Drum untuk memori utama
  - Sejumlah kecil memori inti sebagai cache untuk drum
- Demand paging digunakan untuk mentransfer informasi antara memori inti dan drum secara otomatis

### Sistem XDS-940

Sistem operasi XDS-940 dirancang di Universitas California di Berkeley pada awal 1960-an.

#### Fitur Utama XDS-940
- Seperti sistem Atlas, menggunakan paging untuk manajemen memori
- Berbeda dengan Atlas, XDS-940 adalah sistem time-sharing

#### Manajemen Memori XDS-940
- Paging hanya digunakan untuk relokasi, bukan untuk demand paging
- Memori virtual setiap proses pengguna: 16-KB kata
- Memori fisik: 64-KB kata
- Setiap halaman: 2-KB kata
- Tabel halaman disimpan di register
- Karena memori fisik lebih besar dari memori virtual, beberapa proses pengguna dapat berada di memori pada saat yang sama

## Referensi
- Buku Teks Sistem Operasi
- Sejarah Komputasi
- Arsitektur Komputer
- Dokumentasi Historis Sistem Operasi

---

*Catatan: Dokumen ini merupakan ringkasan dari bahan pembelajaran tentang sejarah dan evolusi sistem operasi.*
