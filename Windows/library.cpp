Mahasiswa *read_data(char *filename, int *total){
	FILE *file;
	file = fopen(filename, "rb");
	if(file == NULL) return NULL;
	if(fread(total, sizeof(int), 1, file) != 1)
		return NULL;
	Mahasiswa *data = (struct Mahasiswa*) malloc(sizeof(Mahasiswa) * *total);
	
	int SizeRead = sizeof(Mahasiswa);
	if(fread(data, SizeRead, *total, file) != *total){
		free(data);
		return NULL;
	}
	if(fclose(file) == EOF){
		free(data);
		return NULL;
	}
	return data;
}
void transisi(){
	SizeData = InputMhs.size();
	for(int i=0; i < SizeData; i++){
		mhs[i].Pk = InputMhs[i].Pk;
		strcpy(mhs[i].nim, InputMhs[i].nim.c_str());
		strcpy(mhs[i].nama, InputMhs[i].nama.c_str());
		strcpy(mhs[i].jurusan, InputMhs[i].jurusan.c_str());
	}	
}
// void cek(){
// 	SizeData = InputMhs.size();
// 	for(int i=0; i < SizeData; i++){
// 		cout << endl << endl << endl;
// 		cout<< mhs[i].Pk 				<< endl
// 				<< mhs[i].nim 		  << endl
// 				<< mhs[i].nama 			<< endl
// 				<< mhs[i].jurusan  	<< endl;
// 	}
// }
int menu(){
	int input;
	system("cls");
	cout 	<< "Program CRUD data mahasiswa	" << endl
				<< "===========================	"	<< endl
				<< "1. Tambah data mahasiswa		" << endl
				<< "2. Tampilkan data mahasiswa	" << endl
				<< "3. Ubah data mahasiswa			" << endl
				<< "4. Hapus data mahasiswa			" << endl
				<< "5. Selesai									" << endl 
				<< "===========================	" << endl
				<< "pilih [1-5]? : "; cin >> input;

	return input;
}
int menampilkan(){
	int counter = 0;
	SizeData = InputMhs.size();
	cout<< left << setw(10) << "no."
			<< left << setw(10) << "pk." 
			<< left << setw(15) << "NIM."
			<< left << setw(30) << "Nama."
			<< left << setw(30) << "Jurusan."
			<< endl;
	for(int i=0; i < SizeData; i++){
		if(InputMhs[i].nim != "\0"){
			counter++;
			cout<< left << setw(10) << counter
					<< left << setw(10) << InputMhs[i].Pk 
					<< left << setw(15) << InputMhs[i].nim 
					<< left << setw(30) << InputMhs[i].nama
					<< left << setw(30) << InputMhs[i].jurusan
					<< endl;
		}
	} 
	if(counter == 0){
		return false;
	}
	return true;
}
void menambah(){
	string nama, jurusan, nim;
	SizeData = InputMhs.size();
	// cout << "ukuran data : " << SizeData << endl;
	// if(Pk != 0) cout << "pk = " << Pk << endl;	
	cout <<"Nama: "; getline(cin>>ws, nama);
	cout << "Jurusan: "; getline(cin>>ws, jurusan);
	cout << "NIM: ";	cin >> nim;
	Pk++;
	// Card c1;
	// c1.suit=s;
	// c1.rank=i

	// InputMhs.push_back(
	// 	{ nama, jurusan, nim, Pk }
	// );	
	InputMahasiswa c1;
	c1.nama=nama;
	c1.jurusan=jurusan;
	c1.nim=nim;
	c1.Pk=Pk;

	InputMhs.push_back(c1);

	menampilkan();
}
void mengubah(){
	int input, counter = 0, CPk;
	string nama, jurusan, nim;
	SizeData = InputMhs.size();
	info_data = menampilkan();
	if(info_data == true){
		cout << "pilih no: "; cin >> input;
		cout << endl << endl << endl;
		input--;
		for(int i = 0; i < SizeData; i++){
			if(i == input){
				counter++;
				CPk = InputMhs[i].Pk;
				cout << "pilihan data:" << endl;
				cout << "NIM\t: " << InputMhs[i].nim << endl;
				cout << "nama\t: " << InputMhs[i].nama << endl;
				cout << "jurusan\t: " << InputMhs[i].jurusan << endl;
				cout << endl;
				cout << "Merubah data: " << endl;
				cout << "NIM: ";	cin >> nim;
				cout <<"Nama: "; getline(cin>>ws, nama);
				cout << "Jurusan: "; getline(cin>>ws, jurusan);
				// InputMhs[i] = {nama, jurusan, nim, CPk};
				InputMhs[i].nama = nama;
				InputMhs[i].jurusan = jurusan;
				InputMhs[i].nim = nim;
				InputMhs[i].Pk = CPk;
				menampilkan();
			}
		}
		if(counter == 0){
			cout << "Salah input nomor" << endl;
		}
	}
}
void menghapus(){
	int input, counter = 0;
	SizeData = InputMhs.size();
	info_data = menampilkan();
	if(info_data == true){
		cout << "Hapus nomor: "; cin >> input;
		input = input - 1;
		for(int i = 0; i < SizeData; i++){
			if(i == input){
				cout << "delete item" << endl;
				// InputMhs.erase(InputMhs.begin()+input);
				InputMhs[i].nama = "";
				InputMhs[i].jurusan = "";
				InputMhs[i].nim = "";

				counter++;
				menampilkan();
			}	
		}
		if(counter == 0){
			cout << "Salah input nomor" << endl;
		}
	}
}
bool write_data(char *filename, Mahasiswa *data, int total){
	FILE *file;
	file = fopen(filename, "wb");
	if( file == NULL ) return false;

	int num = sizeof(int);
	if(fwrite(&total, num, 1, file) != 1) 
		return false;

	int SizeWrite = sizeof(Mahasiswa);
	if(fwrite(data, SizeWrite, total, file) != total)
		return false;

	if(fclose(file) == EOF) return false;
	return true;
}