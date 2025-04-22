#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constants
#define MAX_PASIEN 21


// struktur untuk menyimpan data pasien
typedef struct {
    char nama[50];
    int umur;
    char alamat[100];
    char penyakit[50];              // array pasien
    char butuhSpesialis[5];
    char spesialisDokter[50];
    int lamainap;
    char jeniskamar[20];
    int nomorkamar;
    int status; // 1 = aktif, 0 = keluar
} Pasien;

// Struktur untuk menyimpan data dokter
typedef struct {
    char hari[10];
    char waktu[20];     // jadwal dokter
} JadwalDokter;

typedef struct {
    char nama[50];
    char spesialis[50];        //dokter
    JadwalDokter jadwal[7];
} Dokter;


// kamarr
typedef struct {
    int nomor;
    char kelas[20];
    int terisi; // 1 = terisi, 0 = kosong
    char namapasien[50];
    int lamapenggunaan;
} Kamar;

//STruktur variable GLoballllllll sheesh
Pasien daftarpasien[MAX_PASIEN];
Dokter daftardokter[5] = {
    {"Dr. Andi", "Jantung", 
        {
            {"Senin", "08:00 - 14:00"},
            {"Rabu", "08:00-14:00"},
            {"Jumat", "13:00-20:00"}
        }
    },
    {"Dr. Budi", "Paru", {
        {"Selasa", "08:00-14:00"},
        {"Kamis", "13:00-20:00"},
        {"Sabtu", "08:00-14:00"}
    }},
    {"Dr. Citra", "Anak", {
        {"Senin", "13:00-20:00"},
        {"Selasa", "13:00-18:00"},
        {"Jumat", "08:00-14:00"}
    }},
    {"Dr. Nolen", "Bedah", {
        {"Selasa", "09:00-14:00"},
        {"Rabu", "11:00-19:00"},
        {"Jumat", "08:30-14:50"}
    }},
    {"Dr. Rahmat", "Kanker", {
        {"Senin", "08:00-14:00"},
        {"Rabu", "08:00-17:00"},
        {"Kamis", "09:30-15:30"}
    }}
};

Kamar daftarkamar[20] = {
    {101, "VIP", 0, "", 0}, {102, "VIP", 0, "", 0}, {103, "VIP", 0, "", 0}, {104, "VIP", 0, "", 0}, {105, "VIP", 0, "", 0},
    {201, "Kelas 1", 0, "", 0}, {202, "Kelas 1", 0, "", 0}, {203, "Kelas 1", 0, "", 0},{204, "Kelas 1", 0, "", 0}, {205, "Kelas 1", 0, "", 0},
    {301, "Kelas 2", 0, "", 0}, {302, "Kelas 2", 0, "", 0}, {303, "Kelas 2", 0, "", 0}, {304, "Kelas 2", 0, "", 0}, {305, "Kelas 2", 0, "", 0},
    {401, "Kelas 3", 0, "", 0}, {402, "Kelas 3", 0, "", 0}, {403, "Kelas 3", 0, "", 0},{404, "Kelas 3", 0, "", 0}, {405, "Kelas 3", 0, "", 0}
    
};

int jumlahpasien = 0;
int jumlahkamar = 20;
int jumlahdokter = 5;

// fungsi bukan nabi boy wajarr!!!

// fungsi - fungsi yang ada di pemograman

void tampilkanDaftarDokter(void);
void tampilkanDaftarHarga(void);
void tampilkanStatusKamar(void);
void updateStatusKamar(void);
int cariKamarKosong(char *kelas);
void tambahPasien(void);
void tampilkanPasien(void);
void cariPasien(void);
void hapusPasien(void);
void tampilkanDashboard(void);
void tampilkanArah(void);
void daftarKamar(void);
void hitungBiaya(void);
void menuPasien(void);
void menuKamar(void);
void menuDokter(void);



//fungsi daftar dokter

void tampilkanDaftarDokter() {
    printf("\nDaftar Dokter dan Jadwal Praktik:\n");
    for (int i = 0; i < jumlahdokter; i++) {
        printf("\n%s - Spesialis %s\n", daftardokter[i].nama, daftardokter[i].spesialis);
        printf("Jadwal Praktik:\n");
        for (int j = 0; j < 3; j++) {
            if (strlen(daftardokter[i].jadwal[j].hari) > 0) {
                printf("- %s: %s\n", 
                    daftardokter[i].jadwal[j].hari,
                    daftardokter[i].jadwal[j].waktu);
            }
        }
    }
}



//fungsi daftar harga kamar
void tampilkanDaftarHarga() {
    printf("\nDaftar Harga Kamar per Hari:\n");
    printf("1. VIP       : Rp. 1.000.000\n");
    printf("2. Kelas 1   : Rp. 750.000\n");
    printf("3. Kelas 2   : Rp. 500.000\n");
    printf("4. Kelas 3   : Rp. 250.000\n");
}

// fungsi status kamar1
void tampilkanStatusKamar() {
    int vip = 0, kelas1 = 0, kelas2 = 0, kelas3 = 0;
    int vipTerisi = 0, kelas1Terisi = 0, kelas2Terisi = 0, kelas3Terisi = 0;
    
    for (int i = 0; i < jumlahkamar; i++) {
        if (strcasecmp(daftarkamar[i].kelas, "VIP") == 0) {
            vip++;
            if (daftarkamar[i].terisi) vipTerisi++;
        } else if (strcasecmp(daftarkamar[i].kelas, "Kelas 1") == 0) {
            kelas1++;
            if (daftarkamar[i].terisi) kelas1Terisi++;
        } else if (strcasecmp(daftarkamar[i].kelas, "Kelas 2") == 0) {
            kelas2++;
            if (daftarkamar[i].terisi) kelas2Terisi++;
        } else if (strcasecmp(daftarkamar[i].kelas, "Kelas 3") == 0) {
            kelas3++;
            if (daftarkamar[i].terisi) kelas3Terisi++;
        }
    }
    
    printf("\nStatus Kamar Rumah Sakit:\n");
    printf("VIP    : %d/%d kamar terisi\n", vipTerisi, vip);
    printf("Kelas 1: %d/%d kamar terisi\n", kelas1Terisi, kelas1);
    printf("Kelas 2: %d/%d kamar terisi\n", kelas2Terisi, kelas2);
    printf("Kelas 3: %d/%d kamar terisi\n", kelas3Terisi, kelas3);
    
    printf("\nDetail Kamar yang Terisi:\n");
    for (int i = 0; i < jumlahkamar; i++) {
        if (daftarkamar[i].terisi) {
            printf("Kamar %d (%s): Ditempati oleh %s\n", 
                   daftarkamar[i].nomor, 
                   daftarkamar[i].kelas, 
                   daftarkamar[i].namapasien);
        }
    }
}
// fungsi cari kamar kosong
int cariKamarKosong(char *kelas) {
    for (int i = 0; i < jumlahkamar; i++) {
        if (strcasecmp(daftarkamar[i].kelas, kelas) == 0 && !daftarkamar[i].terisi) {
            return i;
        }
    }
    return -1;
}

// fungsi update status kamar
void updateStatusKamar() {
    char nama[50];
    char kelasKamarBaru[20];
    int nomorKamarBaru;
    
    printf("\nMasukkan nama pasien: ");
    scanf(" %[^\n]s", nama);

    // Cari pasien
    for (int i = 0; i < jumlahpasien; i++) {
        if (strcasecmp(daftarpasien[i].nama, nama) == 0 && daftarpasien[i].status == 1) {
            printf("\nInfo Pasien Saat Ini:\n");
            printf("Kelas Kamar: %s\n", daftarpasien[i].jeniskamar);
            printf("Nomor Kamar: %d\n", daftarpasien[i].nomorkamar);
            
            // Input kamar baru
            printf("\nMasukkan kelas kamar baru (VIP/Kelas 1/Kelas 2/Kelas 3): ");
            scanf(" %[^\n]s", kelasKamarBaru);
            
            // Cari kamar kosong di kelas yang diminta
            int indexKamarBaru = cariKamarKosong(kelasKamarBaru);
            if (indexKamarBaru == -1) {
                printf("Maaf, kamar %s sedang penuh.\n", kelasKamarBaru);
                return;
            }
            
            // Update status kamar lama (kosongkan)
            for (int j = 0; j < jumlahkamar; j++) {
                if (daftarkamar[j].nomor == daftarpasien[i].nomorkamar) {
                    daftarkamar[j].terisi = 0;
                    strcpy(daftarkamar[j].namapasien, "");
                    daftarkamar[j].lamapenggunaan = 0;
                    break;
                }
            }
            
            // Update status kamar baru
            nomorKamarBaru = daftarkamar[indexKamarBaru].nomor;
            daftarkamar[indexKamarBaru].terisi = 1;
            strcpy(daftarkamar[indexKamarBaru].namapasien, nama);
            daftarkamar[indexKamarBaru].lamapenggunaan = daftarpasien[i].lamainap;
            
            // Update data pasien
            strcpy(daftarpasien[i].jeniskamar, kelasKamarBaru);
            daftarpasien[i].nomorkamar = nomorKamarBaru;
            
            printf("\nPasien berhasil dipindahkan ke kamar %d (%s)\n", 
                   nomorKamarBaru, kelasKamarBaru);
            return;
        }
    }
    printf("Pasien tidak ditemukan.\n");
}


//fungssi mengelola data pasien

void tambahPasien() {
    if (jumlahpasien >= MAX_PASIEN) {
        printf("Kapasitas pasien penuh!\n");
        return;
    }

    printf("\n=== Pendaftaran Pasien Baru ===\n");
    printf("Nama: ");
    scanf(" %[^\n]s", daftarpasien[jumlahpasien].nama);
    printf("Umur: ");
    scanf("%d", &daftarpasien[jumlahpasien].umur);
    printf("Alamat: ");
    scanf(" %[^\n]s", daftarpasien[jumlahpasien].alamat);
    printf("Jenis Penyakit: ");
    scanf(" %[^\n]s", daftarpasien[jumlahpasien].penyakit);
    printf("Butuh Dokter Spesialis? (y/n): ");
    scanf(" %s", daftarpasien[jumlahpasien].butuhSpesialis);

    if (daftarpasien[jumlahpasien].butuhSpesialis[0] == 'y') {
        tampilkanDaftarDokter();
        printf("Spesialis yang dibutuhkan: ");
        scanf(" %[^\n]s", daftarpasien[jumlahpasien].spesialisDokter);
    }

    printf("Lama Menginap (hari): ");
    scanf("%d", &daftarpasien[jumlahpasien].lamainap);

    tampilkanDaftarHarga();
    tampilkanStatusKamar();

    printf("Jenis Kamar (VIP/Kelas 1/Kelas 2/Kelas 3): ");
    scanf(" %[^\n]s", daftarpasien[jumlahpasien].jeniskamar);

        //proses untuk memberi tahukan status kamar
    int indexKamar = cariKamarKosong(daftarpasien[jumlahpasien].jeniskamar);
    if (indexKamar == -1) {
        printf("Maaf, kamar %s sedang penuh atau tidak ada\n", daftarpasien[jumlahpasien].jeniskamar);
        return;
    }

    daftarpasien[jumlahpasien].nomorkamar = daftarkamar[indexKamar].nomor;
    daftarpasien[jumlahpasien].status = 1;


         // update status kamar
    daftarkamar[indexKamar].terisi = 1;
    strcpy(daftarkamar[indexKamar].namapasien, daftarpasien[jumlahpasien].nama);
    daftarkamar[indexKamar].lamapenggunaan = daftarpasien[jumlahpasien].lamainap;

    jumlahpasien++;
    printf("Pasien berhasil didaftarkan!\n");
}


// fungsi menampilkan daftar pasien
void tampilkanPasien() {
    // sortingg berdasarkan jenis kamar dari VIP sampai bawah menggunakan bubble sort
    Pasien temp;
    for (int i = 0; i < jumlahpasien - 1; i++) {
        for (int j = 0; j < jumlahpasien - i - 1; j++) {
            if (strcmp(daftarpasien[j].jeniskamar, daftarpasien[j + 1].jeniskamar) > 0) {
                temp = daftarpasien[j];
                daftarpasien[j] = daftarpasien[j + 1];
                daftarpasien[j + 1] = temp;
            }
        }
    }

 // Menampilkan daftar pasien berdasarkan bubble sort
    printf("\n=== Daftar Pasien ===\n");
    for (int i = 0; i < jumlahpasien; i++) {
        if (daftarpasien[i].status == 1) {          //pasien yang aktif == 1
            printf("\nPasien %d:\n", i + 1);
            printf("Nama: %s\n", daftarpasien[i].nama);
            printf("Umur: %d\n", daftarpasien[i].umur);
            printf("Alamat: %s\n", daftarpasien[i].alamat);
            printf("Penyakit: %s\n", daftarpasien[i].penyakit);
            printf("Butuh Spesialis: %s\n", daftarpasien[i].butuhSpesialis);
            if (daftarpasien[i].butuhSpesialis[0] == 'y') {
                printf("Dokter Spesialis : %s\n", daftarpasien[i].spesialisDokter);
            }
            printf("Lama Inap: %d hari\n", daftarpasien[i].lamainap);
            printf("Jenis Kamar: %s\n", daftarpasien[i].jeniskamar);
        }
    }
}

// fungsi mencari pasien menggunakan linear search

     // linearsearch memmiliki kelemahan tidak efisien untuk daftar yang panjang

void cariPasien() {
    char nama[50];
    int found = 0;  // untuk melacak pasien ditemukan atau tidak

    printf("\nMasukkan nama pasien: ");
    scanf(" %[^\n]s", nama);     // memintaa inputan nama yang ingin dicari

     // proses
    for (int i = 0; i < jumlahpasien; i++) {
        if (strcasecmp(daftarpasien[i].nama, nama) == 0 && daftarpasien[i].status == 1) {
            printf("\nData Pasien Ditemukan:\n");
            printf("Nama: %s\n", daftarpasien[i].nama);
            printf("Umur: %d\n", daftarpasien[i].umur);
            printf("Alamat: %s\n", daftarpasien[i].alamat);
            printf("Penyakit: %s\n", daftarpasien[i].penyakit);
            printf("Butuh Spesialis: %s\n", daftarpasien[i].butuhSpesialis);
              if (daftarpasien[i].butuhSpesialis[0] == 'y') {
                printf("Dokter Spesialis : %s\n", daftarpasien[i].spesialisDokter);
            }
            printf("Lama Inap: %d hari\n", daftarpasien[i].lamainap);
            printf("Jenis Kamar: %s\n", daftarpasien[i].jeniskamar);
            printf("Nomor Kamar: %d\n", daftarpasien[i].nomorkamar);
            found = 1;
            break;
        }
    }

    if (!found) {    //jika pasien tidak ditemukan
        printf("Pasien tidak ditemukan.\n");
    }
}

// fungsi untuk menghapus pasien
void hapusPasien() {
    char nama[50];
    int found = 0;

    printf("\nMasukkan nama pasien yang akan dihapus: ");
    scanf(" %[^\n]s", nama);
    // masih menggunakan linear search

    for (int i = 0; i < jumlahpasien; i++) {
        if (strcasecmp(daftarpasien[i].nama, nama) == 0 && daftarpasien[i].status == 1) {
         // mengubah status kamar menjadi kosong
            for (int j = 0; j < jumlahkamar; j++) {
                if (daftarkamar[j].nomor == daftarpasien[i].nomorkamar) {
                    daftarkamar[j].terisi = 0;
                    strcpy(daftarkamar[j].namapasien, "");
                    daftarkamar[j].lamapenggunaan = 0;
                    break;
                }
            }
              // Mengubah status pasien menjadi tidak aktif
            daftarpasien[i].status = 0;
            printf("Data pasien berhasil dihapus.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Pasien tidak ditemukan.\n");
    }
}

//fungsi untuk menampilkan dashboard
void tampilkanDashboard() {
    int jumlahRuanganKosong = 0;
    int jumlahRuanganTerisi = 0;
    int jumlahPasienAktif = 0;

    // Hitung jumlah ruangan kosong dan terisi
    for (int i = 0; i < jumlahkamar; i++) {
        if (daftarkamar[i].terisi == 0) {
            jumlahRuanganKosong++;
        } else {
            jumlahRuanganTerisi++;
        }
    }

    // Hitung jumlah pasien aktif
    for (int i = 0; i < jumlahpasien; i++) {
        if (daftarpasien[i].status == 1) {
            jumlahPasienAktif++;
        }
    }

    printf("\n=== Dashboard Rumah Sakit ===\n");
    printf("Jumlah Pasien Aktif: %d\n", jumlahPasienAktif);
    printf("Jumlah Dokter: %d\n", jumlahdokter);
    printf("Jumlah Ruangan Kosong: %d\n", jumlahRuanganKosong);
    printf("Jumlah Ruangan Terisi: %d\n", jumlahRuanganTerisi);
}



// fungsi untuk menampilkan arah lokasi
void tampilkanArah() {
    int pintu;
    int tujuan;
    
    printf("\n=== Petunjuk Arah ===\n");
    printf("Masuk dari:\n");
    printf("1. Pintu Utama\n");
    printf("2. Pintu Samping\n");
    printf("Pilihan: ");
    scanf("%d", &pintu);
    
    printf("\nTujuan:\n");
    printf("1. Kamar VIP\n");
    printf("2. Kamar Kelas 1\n");
    printf("3. Kamar Kelas 2\n");
    printf("4. Kamar Kelas 3\n");
    printf("5. IGD\n");
    printf("6. Apotek\n");
    printf("Pilihan: ");
    scanf("%d", &tujuan);
    
    printf("\nPetunjuk Arah:\n");
    if (pintu == 1) {
        printf("1. Masuk dari pintu utama\n");
        printf("2. Belok kiri menuju lobby utama\n");
    } else {                                                // proses masuk dari pintu mana
        printf("1. Masuk dari pintu samping\n");
        printf("2. Jalan lurus menuju lobby utama\n");
    }

    switch(tujuan) {
        case 5: // IGD
            printf("3. Lurus melewati lobby\n");                    // proses ke igd
            printf("4. Belok kanan, IGD ada di ujung koridor\n");
            break;
        case 6: // Apotek
            printf("3. Lurus melewati lobby\n");
            printf("4. Belok kiri, Apotek ada di sebelah kanan\n");   // ke apotek
            break;
        default: // Semua kamar yang perlu pakai lift
            if (pintu == 1) {
                printf("3. Naik lift di sebelah kanan\n");
            } else {
                printf("3. Naik lift di sebelah kiri\n");
            }
            
            switch(tujuan) {
                case 1:
                    printf("4. Naik ke lantai 5 - Kamar VIP\n");
                    printf("5. Masuk ke Ruangan yang anda Tuju\n");
                    break;
                case 2:
                    printf("4. Naik ke lantai 4 - Kamar Kelas 1\n");
                    printf("5. Masuk ke Ruangan yang anda Tuju\n");
                    break;
                case 3:
                    printf("4. Naik ke lantai 3 - Kamar Kelas 2\n");
                    printf("5. Masuk ke Ruangan yang anda Tuju\n");
                    break;
                case 4:
                    printf("4. Naik ke lantai 2 - Kamar Kelas 3\n");
                    printf("5. Masuk ke Ruangan yang anda Tuju\n");
                    break;
            }
    }
}

// fungsi untuk mengelola kamar

void daftarKamar() {
    int pilihan;
    int validInput = 0;

    do {
        printf("\n=== Manajemen Kamar ===\n");
        printf("1. Daftar Kamar dan Fasilitas\n");      // daftar pilihan
        printf("2. Status Kamar\n");
        printf("3. Update Status Kamar\n");
        printf("4. Kembali ke Menu Utama\n");
        
        do {
            printf("Pilihan: ");
            if (scanf("%d", &pilihan) == 1 && pilihan >= 1 && pilihan <= 4) {
                validInput = 1;                                                     // proses pilihan
            } else {
                printf("Input tidak valid. Silakan pilih 1-4.\n");
                while (getchar() != '\n');
            }
        } while (!validInput);

        switch(pilihan) {                                           // pilhan pertama
            case 1:
                printf("\n=== Daftar Kamar dan Fasilitas ===\n");
                printf("\n1. Kamar VIP (Rp. 1.000.000/hari)\n");
                printf("   Fasilitas:\n");
                printf("   - Kamar ukuran 6x8 meter\n");
                printf("   - Tempat tidur elektrik\n");
                printf("   - AC dan TV LED 42 inch\n");
                printf("   - Kamar mandi dalam dengan air panas\n");
                printf("   - Sofa dan meja tamu\n");
                printf("   - Kulkas mini\n");
                printf("   - Makan 3x sehari dengan menu spesial\n");
                
                printf("\n2. Kamar Kelas 1 (Rp. 750.000/hari)\n");
                printf("   Fasilitas:\n");
                printf("   - Kamar ukuran 5x6 meter\n");
                printf("   - Tempat tidur elektrik\n");
                printf("   - AC dan TV LED 32 inch\n");
                printf("   - Kamar mandi dalam\n");
                printf("   - Sofa untuk penunggu\n");
                printf("   - Makan 3x sehari\n");
                
                printf("\n3. Kamar Kelas 2 (Rp. 500.000/hari)\n");
                printf("   Fasilitas:\n");
                printf("   - Kamar ukuran 5x5 meter untuk 2 pasien\n");
                printf("   - Tempat tidur standar\n");
                printf("   - AC dan TV 24 inch\n");
                printf("   - Kamar mandi dalam\n");
                printf("   - Kursi penunggu\n");
                printf("   - Makan 3x sehari\n");
                
                printf("\n4. Kamar Kelas 3 (Rp. 250.000/hari)\n");
                printf("   Fasilitas:\n");
                printf("   - Kamar ukuran 6x8 meter untuk 4 pasien\n");
                printf("   - Tempat tidur standar\n");
                printf("   - Kipas angin\n");
                printf("   - Kamar mandi luar\n");
                printf("   - Kursi penunggu\n");
                printf("   - Makan 3x sehari\n");
                break;
            case 2:                             // pilihan kedua
                tampilkanStatusKamar();
                break;
            case 3:                             // pilihan ketiga
                updateStatusKamar();
                break;
            case 4:
                printf("Kembali ke menu utama...\n");   // pilihan ketiga
                break;
        }
    } while (pilihan != 4);
}

// fungsi untuk menghitung biaya

void hitungBiaya() {
    char nama[50];
    int found = 0;
    float biaya = 0;

    printf("\nMasukkan nama pasien: ");
    scanf(" %[^\n]s", nama);

    for (int i = 0; i < jumlahpasien; i++) {
        if (strcasecmp(daftarpasien[i].nama, nama) == 0 && daftarpasien[i].status == 1) {
            printf("\nInformasi Biaya:\n");
            printf("Nama: %s\n", daftarpasien[i].nama);
            printf("Umur: %d tahun\n", daftarpasien[i].umur);                         // menampilkan data pasien yang dihitung biayanya
            printf("Alamat: %s\n", daftarpasien[i].alamat);
            printf("__________________________\n");
            printf("Lama Menginap: %d hari\n", daftarpasien[i].lamainap);
            printf("Jenis Kamar: %s\n", daftarpasien[i].jeniskamar);


 // proses menghitung biaya
            if (strcasecmp(daftarpasien[i].jeniskamar, "VIP") == 0) {
                biaya = daftarpasien[i].lamainap * 1000000;
            } else if (strcasecmp(daftarpasien[i].jeniskamar, "Kelas 1") == 0) {
                biaya = daftarpasien[i].lamainap * 750000;
            } else if (strcasecmp(daftarpasien[i].jeniskamar, "Kelas 2") == 0) {
                biaya = daftarpasien[i].lamainap * 500000;
            } else if (strcasecmp(daftarpasien[i].jeniskamar, "Kelas 3") == 0) {
                biaya = daftarpasien[i].lamainap * 250000;
            }
            printf("Total Biaya: Rp. %.2f\n", biaya);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Pasien tidak ditemukan!\n");
    }
}

// fungsi menu pasien
void menuPasien() {
    int pilihan;
    do {
        printf("\n=== Menu Pasien ===\n");
        printf("1. Tambah Pasien\n");
        printf("2. Tampilkan Daftar Pasien\n");
        printf("3. Cari Pasien\n");
        printf("4. Hapus Pasien\n");
        printf("5. Kembali ke Menu Utama\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                tambahPasien();
                break;
            case 2:
                tampilkanPasien();
                break;
            case 3:
                cariPasien();
                break;
            case 4:
                hapusPasien();
                break;
            case 5:
                printf("Kembali ke menu utama...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 5);
}

void menuKamar() {
    daftarKamar();
}

void menuDokter() {
    tampilkanDaftarDokter();
}

// untuk masuk sebagai  menu user                                                                                                   
void menuUser(){
int pilihan;
do{
    printf("======== Selamat Datang di Menu User ======== \n");
    printf("Masukkan pilihan :\n");
    printf("1. Tampilkan Arah\n");
    printf("2. Keluar\n");
    printf("Pilihan :");
    scanf("%d",&pilihan);
    switch (pilihan){
    case 1:
    tampilkanArah(); 
        break;
    
    case 2:
     
     printf("Terimakasih telah menggunakan aplikasi ini :)" );
    
        break;
    }
}while (pilihan !=2);

}
// jika masuk sebagai admin
void admin() {
    int pilihan;
    
    do {
        printf("\n=== SISTEM MANAJEMEN RUMAH SAKIT ===\n");
        printf("1. Menu Pasien\n");
        printf("2. Arah Lokasi\n");
        printf("3. Menu Kamar\n");
        printf("4. Hitung Biaya\n");
        printf("5. Menu Dokter\n");
        printf("6. Dashboard Rawat Inap\n");
        printf("7. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        
        switch(pilihan) {
            case 1:
                menuPasien();
                break;
            case 2:
                tampilkanArah();
                break;
            case 3:
                menuKamar();
                break;
            case 4:
                hitungBiaya();
                break;
            case 5:
                menuDokter();
                break;
            case 6:
            tampilkanDashboard();
                break;
            case 7:
                printf("Terima kasih telah menggunakan sistem ini!\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 7);
    
}
int main(){
    int pilihanlogin;
printf("Login Sebagai apa :\n");
printf("1. Pengunjung / Pasien\n");
printf("2. Admin\n");
  printf("Pilihan :");
scanf("%d",&pilihanlogin);
if(pilihanlogin == 1){
    menuUser();
}else if(pilihanlogin == 2){
    admin();
}else{
    printf("Input Tidak Valid");
}
return 0;
}