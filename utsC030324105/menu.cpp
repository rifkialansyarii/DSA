#include <iostream>
#include <conio.h>
using namespace std;

void dMenu();
void InputData(int data[], int& tagging);
void OutputData(int data[], int tagging);
void SelectionSort(int data[]);
void sepatahKata();
void mPertama(string pesan);
int len;

int main() {
    int data[100];
    int tag = 0;

    char pl;
    do {
        dMenu();
        pl = getch();
        
        switch (pl) {
            case '1':
                system("cls");
                InputData(data, tag);
                getch();
                break;

            case '2':
                system("cls");
                OutputData(data, tag);
                getch();
                break;

            case '3':
                system("cls");
                SelectionSort(data);
                getch();
                break;

            case '4':
                system("cls");
                sepatahKata();
                getch();
                break;

            case '5':
                break;
            
            default:
                system("cls");
                cout << "Pilihan Tidak Tersedia";
                getch(); // tetap dipakai agar user sempat baca pesan
                break;
        }

    } while (pl != '5');
    
    return 0;
}

// Menu
void dMenu() {
    system("cls");
    cout << "Aplikasi Sorting Insertion" << "\n";       
    cout << "1. Memasukkan data" << "\n";            
    cout << "2. Menampilkan data" << "\n";            
    cout << "3. Sorting" << "\n";           
    cout << "4. Sepatah kata" << "\n";            
    cout << "5. Exit" << "\n";           
    cout << "Masukan angka :";        
}

// Memasukkan maksimum jumlah data dan memasukkan data - Pilihan ke-1
void InputData(int data[], int& tagging) {
    mPertama("ke-1");

    cout << "Masukkan Maksimum Data: ";
    cin >> len;

    for (int i = 0; i < len; i++) {
        cout << "Masukkan data (Maks " << len << "): ";
        cin >> data[i]; 
        tagging += 1;
    }
}

// Menampilkan data - Pilihan ke-2
void OutputData(int data[], int tagging) {
    mPertama("ke-2");

    if (tagging == 0) {
        cout << "Data belum ditambahkan, mohon masukkan data pada menu 1!";
    } else {
        cout << "Data Anda: ";
        for (int i = 0; i < len; i++) {
            cout << data[i] << " ";
        }
    }
}

// Ascending Selection Sort
void asc_selection_sort(int data[]) {
    for (int i = 0; i < len - 1; i++) {
        int pos = i;   
        for (int j = i + 1; j < len; j++) {
            if (data[pos] > data[j]) pos = j;
        }
        if (pos != i) swap(data[i], data[pos]);
    }
}

// Descending Selection Sort
void desc_selection_sort(int data[]) {
    for (int i = 0; i < len - 1; i++) {
        int pos = i;
        for (int j = i + 1; j < len; j++) {
            if (data[pos] < data[j]) pos = j;
        }
        if (pos != i) swap(data[i], data[pos]);
    }
}

// SelectionSort - Pilihan ke-3
void SelectionSort(int data[]) {
    mPertama("ke-3");
    int select;

    cout << "Pilih tipe sorting:" << endl
         << "1. Ascending" << endl
         << "2. Descending" << endl
         << "Masukkan Angka: ";
    cin >> select;

    switch (select) {
        case 1:
            asc_selection_sort(data);
            cout << "Data berhasil diurutkan (Ascending). Silahkan cek pada menu 2" << endl;
            break;

        case 2:
            desc_selection_sort(data);
            cout << "Data berhasil diurutkan (Descending). Silahkan cek pada menu 2" << endl;
            break;

        default:
            cout << "Pilihan tidak tersedia." << endl;
            break;
    }
}

// Sepatah kata untuk pilihan ke-4
void sepatahKata() {
    mPertama("ke-4");
    cout << "Indonesia Bisa, Kita Juara";
}

// Judul Menu Pilihan
void mPertama(string pesan) {
    system("cls");
    cout << "Menu " << pesan << endl;
    cout << "--------------------------" << endl;
}
