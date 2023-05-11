#include <iostream>
#include <array>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <vector>
using namespace std;
// Akan dijadikan input-tan
struct InputMahasiswa{
	string nama, jurusan, nim;
	int Pk;
};
// Akan ditransisikan ke Mahasiswa ke Student
struct Mahasiswa{
	char nama[254], jurusan[254], nim[254];
	int Pk;
};
vector<InputMahasiswa> InputMhs;
struct Mahasiswa* mhs = (struct Mahasiswa*) malloc(999*sizeof(Mahasiswa));
// menghitung banyak data
int SizeData;
int Pk;
// Pengkondisian untuk cek apakah ada data
// dalam function menampilkan() atau tidak
bool info_data;
// Nama file yg akan disave
char nama_file[] = "daftar.bin";
// code di file lain
#include "library.h"
int main(int argc, char const *argv[]){
	// Deklarasi
	int input_menu;
	char lanjutkan;
	// Read
	int total = InputMhs.size();
	Mahasiswa *file_data;
	file_data = read_data(nama_file, &total);
	if(file_data != NULL){
		for(int i = 0; i < total; i++){
			// InputMhs.push_back({
			// 	file_data[i].nama, 
			// 	file_data[i].jurusan,
			// 	file_data[i].nim,
			// 	file_data[i].Pk
			// });	
			InputMahasiswa c2;
			c2.nama=file_data[i].nama;
			c2.jurusan=file_data[i].jurusan;
			c2.nim=file_data[i].nim;
			c2.Pk=file_data[i].Pk;

			InputMhs.push_back(c2);

			if(i == total-1){
				Pk = file_data[i].Pk;			
			}
		}
	}
	// inti code
	input_menu = menu();
	while(input_menu != 5){
		switch(input_menu){
			case 1:
				cout << "Menambah data mahasiswa" << endl;
				menambah();
				break;
			case 2:
				cout << "Membaca data mahasiswa" << endl;
				menampilkan();
				break;
			case 3:
				cout << "Merubah data mahasiswa" << endl;
				mengubah();
				break;
			case 4:
				cout << "Menghapus data mahasiswa" << endl;
				menghapus();
				break;
			default:
				cout << "Invalid input.." << endl;
		}
		transisi();
		if(!(write_data(nama_file, mhs, InputMhs.size()))){
			system("clear");
			printf("Error writing to file..\n");
			return 1;
		}	
ulangi:
		cout << "Lanjutkan?(y/n) : "; cin >> lanjutkan;
		if( (lanjutkan == 'Y') || (lanjutkan == 'y') ){
			input_menu = menu();			
		}
		else if( (lanjutkan == 'N') || (lanjutkan == 'n') ){
			break;
		}
		else {
			goto ulangi;
		}
	}
	return 0;
} 