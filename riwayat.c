#include <stdio.h>
#include <string.h>
#include "riwayat.h"

/* Format satu baris di riwayat.txt:
   username film bioskop tanggal jam kursi camilan rasa ukuranPopcorn
   minuman ukuranMinuman metode total */

/* Membaca satu baris dari riwayat.txt. Mengembalikan 1 jika berhasil */
int bacaBaris(FILE *fp, Pesanan *p) {
    return fscanf(fp, "%19s %d %d %d %d %d %d %d %d %d %d %d %d", p->username,
                  &p->film, &p->bioskop, &p->tanggal, &p->jam, &p->kursi,
                  &p->camilan, &p->rasa, &p->ukuranPopcorn, &p->minuman,
                  &p->ukuranMinuman, &p->metode, &p->total) == 13;
}

void simpanRiwayat(Pesanan p) {
    FILE *fp = fopen(FILE_RIWAYAT, "a");

    if (fp == NULL) {
        printf("Gagal menyimpan riwayat!\n");
        return;
    }
    fprintf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d\n", p.username, p.film,
            p.bioskop, p.tanggal, p.jam, p.kursi, p.camilan, p.rasa,
            p.ukuranPopcorn, p.minuman, p.ukuranMinuman, p.metode, p.total);
    fclose(fp);
}

void tampilkanRiwayat(char *username) {
    FILE *fp = fopen(FILE_RIWAYAT, "r");
    Pesanan p;
    int nomor = 0;

    printf("\n===== RIWAYAT TRANSAKSI =====\n");

    if (fp != NULL) {
        while (bacaBaris(fp, &p)) {
            if (strcmp(p.username, username) == 0) {
                nomor++;
                printf("%d. %s | %s | %s %s | Kursi %d | ", nomor, namaFilm[p.film],
                       namaBioskop[p.bioskop], namaTanggal[p.tanggal],
                       namaJam[p.jam], p.kursi);
                cetakCamilan(p);
                printf(" | Rp%d | %s\n", p.total, namaMetode[p.metode]);
            }
        }
        fclose(fp);
    }

    if (nomor == 0) {
        printf("Belum ada riwayat transaksi.\n");
    }
}

int kursiTerisi(Pesanan p, int kursi) {
    FILE *fp = fopen(FILE_RIWAYAT, "r");
    Pesanan lain;

    if (fp == NULL) {
        return 0;
    }

    while (bacaBaris(fp, &lain)) {
        if (lain.film == p.film && lain.bioskop == p.bioskop &&
            lain.tanggal == p.tanggal && lain.jam == p.jam && lain.kursi == kursi) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
