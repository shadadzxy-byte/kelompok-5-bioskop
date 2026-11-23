#include <stdio.h>
#include "konfirmasi.h"

void tampilkanBukti(Pesanan p) {
    printf("\n=================================\n");
    printf("      BUKTI PEMESANAN TIKET\n");
    printf("=================================\n");
    printf("Nama pemesan : %s\n", p.username);
    printf("Film         : %s\n", namaFilm[p.film]);
    printf("Bioskop      : %s\n", namaBioskop[p.bioskop]);
    printf("Hari         : %s\n", namaTanggal[p.tanggal]);
    printf("Jam tayang   : %s\n", namaJam[p.jam]);
    printf("Kursi        : %d\n", p.kursi);
    printf("Camilan      : ");
    cetakCamilan(p);
    printf("\n");
    printf("Total bayar  : Rp%d\n", p.total);
    printf("Metode bayar : %s\n", namaMetode[p.metode]);
    printf("---------------------------------\n");
    printf("Pemesanan berhasil. Terima kasih!\n");
    printf("=================================\n");
}
