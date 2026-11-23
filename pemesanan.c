#include <stdio.h>
#include <string.h>
#include "pemesanan.h"
#include "riwayat.h"

/* Menampilkan daftar film beserta harga weekdays dan weekend */
int pilihFilm() {
    printf("\n--- PILIH FILM ---\n");
    for (int i = 0; i < JUMLAH_FILM; i++) {
        printf("%d. %s - Weekdays Rp%d, Weekend Rp%d\n", i + 1, namaFilm[i],
               hargaWeekdays[i], hargaWeekend[i]);
    }
    return bacaPilihan(JUMLAH_FILM);
}

/* Menampilkan denah kursi, lalu meminta pengguna memilih kursi yang kosong.
   Mengembalikan 0 jika semua kursi sudah penuh */
int pilihKursi(Pesanan *p) {
    int kursi, penuh = 1;

    printf("\n--- PILIH KURSI ---\n");
    printf("      [ L A Y A R ]\n");
    for (int i = 1; i <= JUMLAH_KURSI; i++) {
        if (kursiTerisi(*p, i)) {
            printf("[ X] ");
        } else {
            printf("[%2d] ", i);
            penuh = 0;
        }
        if (i % 5 == 0) printf("\n");
    }

    if (penuh) {
        printf("Maaf, semua kursi sudah terisi.\n");
        return 0;
    }

    printf("Pilih nomor kursi: ");
    scanf("%d", &kursi);
    while (kursi < 1 || kursi > JUMLAH_KURSI || kursiTerisi(*p, kursi)) {
        printf("Kursi tidak tersedia, pilih lagi: ");
        scanf("%d", &kursi);
    }

    p->kursi = kursi;
    return 1;
}

/* Memilih paket camilan. Jika ada popcorn, lanjut memilih rasa dan ukuran.
   Jika ada minuman, lanjut memilih jenis dan ukuran */
void pilihCamilan(Pesanan *p) {
    p->camilan = pilihMenu("PILIH PAKET CAMILAN", namaCamilan, NULL, JUMLAH_CAMILAN);

    if (adaPopcorn(*p)) {
        p->rasa = pilihMenu("PILIH RASA POPCORN", namaRasa, NULL, JUMLAH_RASA);
        p->ukuranPopcorn = pilihMenu("PILIH UKURAN POPCORN", namaUkuran,
                                     hargaPopcorn[p->rasa], JUMLAH_UKURAN);
    }
    if (adaMinuman(*p)) {
        p->minuman = pilihMenu("PILIH MINUMAN", namaMinuman, NULL, JUMLAH_MINUMAN);
        p->ukuranMinuman = pilihMenu("PILIH UKURAN MINUMAN", namaUkuran,
                                     hargaMinuman[p->minuman], JUMLAH_UKURAN);
    }
}

int pesanTiket(Pesanan *p, char *username) {
    char *aksi[2] = {"Lanjut ke pembayaran", "Batalkan pesanan"};

    strcpy(p->username, username);
    p->rasa = 0;
    p->ukuranPopcorn = 0;
    p->minuman = 0;
    p->ukuranMinuman = 0;

    p->film    = pilihFilm();
    p->bioskop = pilihMenu("PILIH LOKASI BIOSKOP", namaBioskop, NULL, JUMLAH_BIOSKOP);
    p->tanggal = pilihMenu("PILIH HARI", namaTanggal, NULL, JUMLAH_TANGGAL);
    p->jam     = pilihMenu("PILIH JAM TAYANG", namaJam, NULL, JUMLAH_JAM);

    if (!pilihKursi(p)) {
        return 0;
    }

    pilihCamilan(p);
    p->total = hitungHargaTiket(*p) + hitungHargaCamilan(*p);

    tampilkanRincian(*p);
    return pilihMenu("KONFIRMASI", aksi, NULL, 2) == 0;
}

void tampilkanRincian(Pesanan p) {
    printf("\n===== RINCIAN PESANAN =====\n");
    printf("Film          : %s\n", namaFilm[p.film]);
    printf("Bioskop       : %s\n", namaBioskop[p.bioskop]);
    printf("Hari          : %s\n", namaTanggal[p.tanggal]);
    printf("Jam           : %s\n", namaJam[p.jam]);
    printf("Kursi         : %d\n", p.kursi);
    printf("Camilan       : ");
    cetakCamilan(p);
    printf("\n");
    printf("Harga tiket   : Rp%d (%s)\n", hitungHargaTiket(p),
           akhirPekan[p.tanggal] ? "Weekend" : "Weekdays");
    printf("Harga camilan : Rp%d\n", hitungHargaCamilan(p));
    printf("TOTAL         : Rp%d\n", p.total);
}
