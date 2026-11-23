#ifndef PEMBAYARAN_H
#define PEMBAYARAN_H

#include "data.h"

/* Memilih metode pembayaran lalu memproses pembayaran.
   Mengembalikan 1 jika berhasil, 0 jika dibatalkan */
int bayar(Pesanan *p);

#endif
