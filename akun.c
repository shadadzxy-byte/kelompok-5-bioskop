#include <stdio.h>
#include <string.h>
#include "akun.h"
#include "data.h"

void daftarAkun() {
    Akun baru, a;
    FILE *fp;

    printf("\n--- DAFTAR AKUN ---\n");
    printf("Username baru: ");
    scanf("%19s", baru.username);
    printf("Password baru: ");
    scanf("%19s", baru.password);

    /* cek apakah username sudah dipakai */
    fp = fopen(FILE_USER, "r");
    if (fp != NULL) {
        while (fscanf(fp, "%19s %19s", a.username, a.password) == 2) {
            if (strcmp(a.username, baru.username) == 0) {
                printf("Username sudah dipakai!\n");
                fclose(fp);
                return;
            }
        }
        fclose(fp);
    }

    /* simpan akun baru di akhir file */
    fp = fopen(FILE_USER, "a");
    if (fp == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }
    fprintf(fp, "%s %s\n", baru.username, baru.password);
    fclose(fp);

    printf("Akun berhasil dibuat! Silakan login.\n");
}

int loginAkun(char *username) {
    Akun input, a;
    FILE *fp;
    int percobaan = 0;

    printf("\n--- LOGIN ---\n");

    while (percobaan < 3) {
        printf("Username: ");
        scanf("%19s", input.username);
        printf("Password: ");
        scanf("%19s", input.password);

        fp = fopen(FILE_USER, "r");
        if (fp == NULL) {
            printf("Belum ada akun. Silakan daftar dulu.\n");
            return 0;
        }

        while (fscanf(fp, "%19s %19s", a.username, a.password) == 2) {
            if (strcmp(a.username, input.username) == 0 &&
                strcmp(a.password, input.password) == 0) {
                fclose(fp);
                strcpy(username, input.username);
                printf("Login berhasil! Selamat datang, %s.\n", username);
                return 1;
            }
        }
        fclose(fp);

        percobaan++;
        printf("Username atau password salah! (%d/3)\n\n", percobaan);
    }

    printf("Anda gagal login 3 kali.\n");
    return 0;
}
