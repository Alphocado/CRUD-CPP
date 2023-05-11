#include "library.cpp"
// read
Mahasiswa *read_data(char *filename, int *total);
int menu();
int menampilkan();
void menambah();
void mengubah();
void menghapus();
// transisi
void transisi();
// write
bool write_data(char *filename, Mahasiswa *data, int total);