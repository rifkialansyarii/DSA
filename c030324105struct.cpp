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
    mahasiswa* ptr = &rifki;

    (*ptr).nim = "C030324105";
    (*ptr).nama = "Rifki Al Ansyari";
    (*ptr).alamat = "Jl. Alalak Utara";
    (*ptr).ipk = 3.7;

    cout << endl << "Data Mahasiswa" << endl << "----------------------" << endl;
    cout << "NIM: " << (*ptr).nim << endl;
    cout << "Nama: " << (*ptr).nama << endl;
    cout << "Alamat: " <<(*ptr).alamat << endl;
    cout << "IPK: " << (*ptr).ipk << endl;




    return 0;


}