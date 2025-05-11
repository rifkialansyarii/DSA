#include <iostream>
#include <conio.h>
using namespace std;

void dMenu();
void InputData(int data[], int& tagging);
void OutputData(int data[], int tagging);
void SelectionSort(int data[]);
void sepatahKata();
int len;

int main() {
  int data[12];
  int tag = 0;

  char pl;
  do
  {
    dMenu();
    pl=getch();
    
    switch (pl)
    {
        case '1':
          system("cls");
          InputData(data, tag);
          //mPertama("pertama");
          getch();
          break;

        case '2':
          //mPertama("ke- dua");
          system("cls");
          OutputData(data, tag);
          getch(); 
          break;

        case '3':
          //mPertama("ke- tiga");
          system("cls");
          SelectionSort(data);
          getch();
          break;

        case '4':
          sepatahKata();
          /* code */
          break;

        case '5':
          /* code */
          break;
        
        default:
          system("cls");
          cout<<"Pilihan Tidak Tersedia";
          getch();
          break;
    }


  } while (pl!='5');
    return 0;
}

//Menu
void dMenu(){
  system("cls");
  cout<<"Aplikasi Sorting Insertion"<<"\n";       
  cout<<"1. Memasukkan data"<<"\n";            
  cout<<"2. Menampilkan data"<<"\n";            
  cout<<"3. Sorting"<<"\n";           
  cout<<"4. Sepatah kata"<<"\n";            
  cout<<"5. Exit"<<"\n";           
  cout<<"Masukan angka :";        

}


void InputData(int data[], int& tagging){
  cout << "Masukkan Maksimum Jumlah Data:";
  cin >> len;
  
  for (int i = 0; i < len; i++){
    cout << "Masukkan data (Maks " << len << "): ";
    cin >> data[i]; 
    tagging += 1;
  }
  
}

void OutputData(int data[], int tagging){
  if(tagging == 0){
    system("cls");
    cout << "Data belum ditambahkan, mohon masukkan data pada menu 1!";
  }else{
    cout << "Data Anda: ";
    for(int i = 0; i < len; i++){
      cout << data[i] << " ";
    }
  }
}

//Ascending Selection Sort
void asc_selection_sort(int data[]){
    for (int i = 0; i < len-1; i++){
        int pos = i;   
        for (int j = i+1; j < len; j++){
            if (data[pos] > data[j]) pos = j;
        }
        if (pos != i) swap(data[i], data[pos]);
    }
}

//Descending Selection Sort
void desc_selection_sort(int data[]){
    for (int i = 0; i < len-1; i++){
        int pos = i;
        for (int j = i+1; j < len; j++){
            if (data[pos] < data[j]) pos = j;
        }
        if (pos != i) swap(data[i], data[pos]);
    }
}

//SelectionSort
void SelectionSort(int data[]){
    int select;
    
    cout << "Pilih tipe sorting:" << endl << "1. Ascending" << endl << "2. Descending" << endl;
    cin >> select;

    switch (select)
    {
    case 1:
        system("cls");
        asc_selection_sort(data);
        cout << "Data berhasil diurutkan (Ascending). Silahkan cek pada menu 2" << endl;
        break;

    case 2:
        system("cls");
        desc_selection_sort(data);
        cout << "Data berhasil diurutkan (Descending). Silahkan cek pada menu 2" << endl;
        break;

    default:
        system("cls");
        cout << "Pilihan tidak tersedia." << endl;
        break;
    }
}



//Sepatah kata untuk pilihan ke-4
void sepatahKata(){
    system("cls");
    cout<<"Indonesia Bisa, Kita Juara";
    getch();
}

//Menu pertama
void mPertama(string pesan){
  system("cls");
  cout<<"hallo saya menu "<<pesan;
  getch();
}