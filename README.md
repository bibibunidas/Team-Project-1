# Sistem Manajemen Rumah Sakit Sederhana

Aplikasi ini adalah sistem manajemen rumah sakit berbasis bahasa C, yang dapat digunakan untuk mengelola data pasien, dokter, kamar, serta memberikan petunjuk arah di lingkungan rumah sakit. Cocok untuk pembelajaran struktur data, algoritma, dan pemrograman prosedural.

---

## Fitur

- **Manajemen Pasien**
  - Tambah, tampilkan, cari, dan hapus data pasien
  - Hitung biaya rawat inap berdasarkan kelas kamar dan lama menginap

- **Manajemen Kamar**
  - Daftar kamar & fasilitas
  - Status kamar (terisi/kosong)
  - Update status kamar (pindah kamar pasien)

- **Manajemen Dokter**
  - Daftar dokter beserta jadwal praktik dan spesialisasi

- **Dashboard**
  - Statistik jumlah pasien aktif, dokter, kamar terisi/kosong

- **Petunjuk Arah**
  - Panduan arah dari pintu masuk ke kamar, IGD, atau apotek

- **Mode Pengguna**
  - **Admin**: akses penuh ke seluruh fitur
  - **Pengunjung/Pasien**: akses fitur petunjuk arah

---

## Struktur Data

- `Pasien`: Data pasien (nama, umur, alamat, penyakit, kebutuhan spesialis, kamar, status, dll)
- `Dokter`: Data dokter (nama, spesialisasi, jadwal praktik)
- `Kamar`: Data kamar (nomor, kelas, status terisi, nama pasien, lama penggunaan)

---

## Cara Menjalankan

1. **Kompilasi:**
gcc -o rs_manajemen main.c

2. **Jalankan Program:**
./rs_manajemen

3. **Pilih mode login:**  
- 1: Pengunjung/Pasien  
- 2: Admin

---

## Kelas & Harga Kamar

| Kelas    | Harga/Hari    | Fasilitas Utama                                 |
|----------|---------------|-------------------------------------------------|
| VIP      | Rp1.000.000   | Kamar besar, AC, TV 42", kamar mandi dalam, kulkas, makan spesial |
| Kelas 1  | Rp750.000     | Kamar luas, AC, TV 32", kamar mandi dalam, sofa penunggu |
| Kelas 2  | Rp500.000     | Kamar sedang (2 pasien), AC, TV 24", kamar mandi dalam |
| Kelas 3  | Rp250.000     | Kamar besar (4 pasien), kipas angin, kamar mandi luar |

---

## Catatan Teknis

- Maksimal pasien: 21
- Maksimal dokter: 5
- Maksimal kamar: 20
- Data hanya tersimpan selama program berjalan (belum ada penyimpanan file)
- Sorting pasien berdasarkan jenis kamar (VIP–Kelas 3)
- Pencarian pasien menggunakan linear search

---


---

## Kontribusi

Silakan fork, modifikasi, dan pull request untuk perbaikan atau penambahan fitur.

---

## Lisensi

Proyek ini bebas digunakan untuk keperluan pembelajaran.

---

**Selamat mencoba dan semoga bermanfaat!**
