#ifndef AKUN_H
#define AKUN_H

typedef struct {
    char username[20];
    char password[20];
} Akun;

/* Membuat akun baru dan menyimpannya ke users.txt */
void daftarAkun();

/* Login (3 kali kesempatan). Mengembalikan 1 jika berhasil, 0 jika gagal.
   Jika berhasil, username disalin ke parameter username */
int loginAkun(char *username);

#endif
