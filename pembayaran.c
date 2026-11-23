#include <stdio.h>
#include "pembayaran.h"

int bayar(Pesanan *p) {
    int uang;

    p->metode = pilihMenu("METODE PEMBAYARAN", namaMetode, NULL, JUMLAH_METODE);

    printf("\nTotal yang harus dibayar: Rp%d\n", p->total);
    printf("Masukkan jumlah uang (0 = batal): Rp");
    scanf("%d", &uang);

    while (uang != 0 && uang < p->total) {
        printf("Uang kurang! Masukkan lagi (0 = batal): Rp");
        scanf("%d", &uang);
    }

    if (uang == 0) {
        printf("Pembayaran dibatalkan.\n");
        return 0;
    }

    if (uang > p->total) {
        printf("Kembalian: Rp%d\n", uang - p->total);
    }
    printf("Pembayaran berhasil!\n");
    return 1;
}
