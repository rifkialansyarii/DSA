#include <iostream>
#include <conio.h>
using namespace std;

void dMenu();
void InputData(int data[], int& tagging);
void OutputData(int data[], int tagging);
void mPertama(string pesan);
void sepatahKata();

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
          mPertama("ke- tiga");
          /* code */
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

//Menu pertama
void mPertama(string pesan){
  system("cls");
  cout<<"hallo saya menu "<<pesan;
  getch();
}

void InputData(int data[], int& tagging){
  for (int i = 0; i < 12; i++){
    cout << "Masukkan data (Maks 12):";
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
    for(int i = 0; i < 12; i++){
      cout << data[i] << " ";
    }
  }
}

//Sepatah kata untuk pilihan ke-4
void sepatahKata(){
    system("cls");
    cout<<"Indonesia Bisa, Kita Juara";
    getch();
}


