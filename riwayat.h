#ifndef RIWAYAT_H
#define RIWAYAT_H

#include "data.h"

/* Menyimpan satu pesanan ke file riwayat.txt */
void simpanRiwayat(Pesanan p);

/* Menampilkan semua riwayat transaksi milik username */
void tampilkanRiwayat(char *username);

/* Mengembalikan 1 jika kursi sudah dipesan pada film, bioskop, tanggal,
   dan jam yang sama dengan p, selain itu 0 */
int kursiTerisi(Pesanan p, int kursi);

#endif
