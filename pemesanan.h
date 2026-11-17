#ifndef PEMESANAN_H
#define PEMESANAN_H

#include "data.h"

/* Memilih film, bioskop, tanggal, jam, kursi, dan camilan.
   Hasilnya disimpan ke p. Mengembalikan 1 jika lanjut ke pembayaran,
   0 jika dibatalkan */
int pesanTiket(Pesanan *p, char *username);

/* Menampilkan rincian dan total harga pesanan */
void tampilkanRincian(Pesanan p);

#endif
