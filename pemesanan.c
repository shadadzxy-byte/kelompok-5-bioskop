#include <stdio.h>
#include <string.h>
#include "pemesanan.h"
#include "riwayat.h"

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

int pesanTiket(Pesanan *p, char *username) {
    char *aksi[2] = {"Lanjut ke pembayaran", "Batalkan pesanan"};

    strcpy(p->username, username);

    p->film    = pilihMenu("PILIH FILM", namaFilm, hargaFilm, JUMLAH_FILM);
    p->bioskop = pilihMenu("PILIH LOKASI BIOSKOP", namaBioskop, NULL, JUMLAH_BIOSKOP);
    p->tanggal = pilihMenu("PILIH TANGGAL", namaTanggal, NULL, JUMLAH_TANGGAL);
    p->jam     = pilihMenu("PILIH JAM TAYANG", namaJam, NULL, JUMLAH_JAM);

    if (!pilihKursi(p)) {
        return 0;
    }

    p->camilan = pilihMenu("PILIH PAKET CAMILAN", namaCamilan, hargaCamilan, JUMLAH_CAMILAN);
    p->total = hargaFilm[p->film] + hargaCamilan[p->camilan];

    tampilkanRincian(*p);
    return pilihMenu("KONFIRMASI", aksi, NULL, 2) == 0;
}

void tampilkanRincian(Pesanan p) {
    printf("\n===== RINCIAN PESANAN =====\n");
    printf("Film          : %s\n", namaFilm[p.film]);
    printf("Bioskop       : %s\n", namaBioskop[p.bioskop]);
    printf("Tanggal       : %s\n", namaTanggal[p.tanggal]);
    printf("Jam           : %s\n", namaJam[p.jam]);
    printf("Kursi         : %d\n", p.kursi);
    printf("Camilan       : %s\n", namaCamilan[p.camilan]);
    printf("Harga tiket   : Rp%d\n", hargaFilm[p.film]);
    printf("Harga camilan : Rp%d\n", hargaCamilan[p.camilan]);
    printf("TOTAL         : Rp%d\n", p.total);
}
