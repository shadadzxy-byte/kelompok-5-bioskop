#include <stdio.h>
#include <string.h>
#include "login.h"

int daftar(void) {
    User baru, u;
    FILE *fp;

    printf("\n--- DAFTAR AKUN ---\n");
    printf("Username Baru: ");
    bacaKata(baru.username);
    printf("Password Baru: ");
    bacaKata(baru.password);

    if (strlen(baru.username) == 0 || strlen(baru.password) == 0) {
        printf("Username dan password tidak boleh kosong!\n");
        return 0;
    }

    /* cek apakah username sudah dipakai */
    fp = fopen(FILE_USER, "r");
    if (fp != NULL) {
        while (fscanf(fp, "%19s %19s", u.username, u.password) == 2) {
            if (strcmp(u.username, baru.username) == 0) {
                printf("Username sudah dipakai!\n");
                fclose(fp);
                return 0;
            }
        }
        fclose(fp);
    }

    /* simpan akun baru di akhir file */
    fp = fopen(FILE_USER, "a");
    if (fp == NULL) {
        printf("Gagal membuka file %s\n", FILE_USER);
        return 0;
    }
    fprintf(fp, "%s %s\n", baru.username, baru.password);
    fclose(fp);

    printf("Akun berhasil dibuat! Silakan login.\n");
    return 1;
}

int login(char *username) {
    User input, u;
    FILE *fp;
    int percobaan = 0;
    int ditemukan;

    printf("\n--- LOGIN ---\n");

    while (percobaan < 3) {
        printf("Username : ");
        bacaKata(input.username);
        printf("Password : ");
        bacaKata(input.password);

        fp = fopen(FILE_USER, "r");
        if (fp == NULL) {
            printf("Belum ada akun. Silakan daftar dulu.\n");
            return 0;
        }

        ditemukan = 0;
        while (fscanf(fp, "%19s %19s", u.username, u.password) == 2) {
            if (strcmp(u.username, input.username) == 0 &&
                strcmp(u.password, input.password) == 0) {
                ditemukan = 1;
                break;
            }
        }
        fclose(fp);

        if (ditemukan) {
            strcpy(username, input.username);
            printf("Login berhasil! Selamat datang, %s.\n", username);
            return 1;
        }

        percobaan++;
        printf("Username atau password salah! (%d/3)\n\n", percobaan);
    }

    printf("Anda gagal login 3 kali.\n");
    return 0;
}
