#include <stdio.h>
#include "data.h"

char *namaFilm[JUMLAH_FILM] = {"Film 1", "Film 2", "Film 3", "Film 4"};
int hargaFilm[JUMLAH_FILM] = {40000, 45000, 50000, 55000};

char *namaBioskop[JUMLAH_BIOSKOP] = {"Cinema Pusat", "Cinema Timur", "Cinema Barat"};
char *namaTanggal[JUMLAH_TANGGAL] = {"18-11-2026", "19-11-2026", "20-11-2026"};
char *namaJam[JUMLAH_JAM] = {"13:00", "16:00", "19:00"};

char *namaCamilan[JUMLAH_CAMILAN] = {"Tanpa camilan", "Minum", "Popcorn", "Popcorn dan Minum"};
int hargaCamilan[JUMLAH_CAMILAN] = {0, 12000, 20000, 30000};

char *namaMetode[JUMLAH_METODE] = {"Tunai", "Transfer Bank", "E-Wallet"};

int pilihMenu(char *judul, char *nama[], int harga[], int n) {
    int pilihan;

    printf("\n--- %s ---\n", judul);
    for (int i = 0; i < n; i++) {
        printf("%d. %s", i + 1, nama[i]);
        if (harga != NULL) {
            printf(" - Rp%d", harga[i]);
        }
        printf("\n");
    }

    printf("Pilih (1-%d): ", n);
    scanf("%d", &pilihan);
    while (pilihan < 1 || pilihan > n) {
        printf("Pilihan tidak valid, ulangi: ");
        scanf("%d", &pilihan);
    }
    return pilihan - 1;
}
