#include <stdio.h>
#include "login.h"

/* Menu setelah login berhasil */
static void menuUtama(const char *username) {
    Pesanan pesanan;
    int pilihan;
    int logout = 0;

    while (!logout) {
        printf("\n===== MENU UTAMA (%s) =====\n", username);
        printf("1. Pesan tiket\n");
        printf("2. Riwayat transaksi\n");
        printf("3. Logout\n");
        printf("Pilih: ");
        pilihan = bacaAngka();

        if (pilihan == 1) {
            /* Pemesanan -> Pembayaran -> Konfirmasi -> simpan Riwayat */
            if (pesanTiket(&pesanan, username)) {
                if (prosesBayar(&pesanan)) {
                    simpanRiwayat(&pesanan);
                    tampilBukti(&pesanan);
                }
            } else {
                printf("Pemesanan dibatalkan.\n");
            }
        } else if (pilihan == 2) {
            tampilRiwayat(username);
        } else if (pilihan == 3) {
            logout = 1;
            printf("Anda telah logout.\n");
        } else {
            printf("Pilihan tidak valid!\n");
        }
    }
}

int main(void) {
    char username[20];
    int pilihan;
    int keluar = 0;

    while (!keluar) {
        printf("\n===== TIKET BIOSKOP =====\n");
        printf("1. Login\n");
        printf("2. Daftar akun\n");
        printf("3. Keluar\n");
        printf("Pilih: ");
        pilihan = bacaAngka();

        if (pilihan == 1) {
            if (login(username)) {
                menuUtama(username);
            }
        } else if (pilihan == 2) {
            daftar();
        } else if (pilihan == 3) {
            keluar = 1;
            printf("Terima kasih!\n");
        } else {
            printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}
