#include <iostream>
using namespace std;

struct mahasiswa{
    string nim;
    string nama;
    string alamat;
    float ipk;
};

int main(){
    mahasiswa rifki;

    rifki.nim = "C030324105";
    rifki.nama = "Rifki Al Ansyari";
    rifki.alamat = "Jl. Alalak Utara";
    rifki.ipk = 3.7;

    cout << endl << "Data Mahasiswa" << endl << "----------------------" << endl;
    cout << "NIM: " << rifki.nim << endl;
    cout << "Nama: " << rifki.nama << endl;
    cout << "Alamat: " <<rifki.alamat << endl;
    cout << "IPK: " << rifki.ipk << endl;

    return 0;
}