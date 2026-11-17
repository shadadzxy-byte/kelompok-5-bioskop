#ifndef DATA_H
#define DATA_H

#define FILE_USER    "users.txt"
#define FILE_RIWAYAT "riwayat.txt"

#define JUMLAH_FILM    4
#define JUMLAH_BIOSKOP 3
#define JUMLAH_TANGGAL 3
#define JUMLAH_JAM     3
#define JUMLAH_CAMILAN 4
#define JUMLAH_METODE  3
#define JUMLAH_KURSI   10

/* Data satu pemesanan.
   film, bioskop, tanggal, jam, camilan, metode berisi nomor indeks array (mulai 0) */
typedef struct {
    char username[20];
    int film;
    int bioskop;
    int tanggal;
    int jam;
    int kursi;
    int camilan;
    int metode;
    int total;
} Pesanan;

/* Daftar pilihan (array) */
extern char *namaFilm[JUMLAH_FILM];
extern int hargaFilm[JUMLAH_FILM];
extern char *namaBioskop[JUMLAH_BIOSKOP];
extern char *namaTanggal[JUMLAH_TANGGAL];
extern char *namaJam[JUMLAH_JAM];
extern char *namaCamilan[JUMLAH_CAMILAN];
extern int hargaCamilan[JUMLAH_CAMILAN];
extern char *namaMetode[JUMLAH_METODE];

/* Menampilkan daftar pilihan lalu mengembalikan indeks yang dipilih (mulai 0).
   Jika harga tidak dipakai, isi dengan NULL */
int pilihMenu(char *judul, char *nama[], int harga[], int n);

#endif
