#ifndef AUTH_H
#define AUTH_H

/* Membuat akun baru dan menyimpannya ke users.txt. Return 1 jika berhasil. */
int daftar(void);

/* Login (3 kali kesempatan). Jika berhasil, username disalin ke 'username'
   dan fungsi mengembalikan 1. */
int login(char *username);

#endif
