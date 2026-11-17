#include <stdio.h>
#include "data.h"
#include "akun.h"
#include "pemesanan.h"
#include "pembayaran.h"
#include "konfirmasi.h"
#include "riwayat.h"

/* Menu setelah login berhasil */
void menuUtama(char *username) {
    Pesanan pesanan;
    int pilihan = 0;

    while (pilihan != 3) {
        printf("\n===== MENU UTAMA (%s) =====\n", username);
        printf("1. Pesan tiket\n");
        printf("2. Riwayat transaksi\n");
        printf("3. Logout\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            /* Pemesanan -> Pembayaran -> Konfirmasi -> Riwayat */
            if (pesanTiket(&pesanan, username) && bayar(&pesanan)) {
                simpanRiwayat(pesanan);
                tampilkanBukti(pesanan);
            } else {
                printf("Pemesanan dibatalkan.\n");
            }
        } else if (pilihan == 2) {
            tampilkanRiwayat(username);
        } else if (pilihan == 3) {
            printf("Anda telah logout.\n");
        } else {
            printf("Pilihan tidak valid!\n");
        }
    }
}

int main() {
    char username[20];
    int pilihan = 0;

    while (pilihan != 3) {
        printf("\n===== TIKET BIOSKOP =====\n");
        printf("1. Login\n");
        printf("2. Daftar akun\n");
        printf("3. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            if (loginAkun(username)) {
                menuUtama(username);
            }
        } else if (pilihan == 2) {
            daftarAkun();
        } else if (pilihan == 3) {
            printf("Terima kasih!\n");
        } else {
            printf("Pilihan tidak valid!\n");
        }
    }
    return 0;
}
