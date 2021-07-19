#include <iostream>
using namespace std;

// Hash Table
struct HashTable
{
  // data
  string username, password;
} dataAkun[26];


// function hash
int hashFunction( string key ){
  return tolower(key[0]) - 97;
}

// cekDaftar
bool cekDaftar( string username, string password )
{
  
  int index = hashFunction(password);

  // cek index masih kosong atau sudah ditempati
  if( dataAkun[index].username != "" && dataAkun[index].password != "" ){
    // kalo sel index hash tidak table kosong
    cout << "User sudah ada!!" << endl;
    return false;
  }else{
    // kalo sel index di hash table kosong
    dataAkun[index].username = username;
    dataAkun[index].password = password;
    return true;
  }

}

// cekLogin
bool cekLogin( string username, string password )
{
  // hashing dulu
  int index = hashFunction(password);

  // cek username & password bener gak
  if( dataAkun[index].username == username && dataAkun[index].password == password ){
    // kalo bener
    return true;
  }else{
    return false;
  }

}

// cekHapusAkun
bool cekHapusAkun(int index)
{
  // cek apakah sel index di hash table kosong atau tidak
  if( dataAkun[index].username == "" && dataAkun[index].password == "" ){
    // kalo selnya kosong
    cout << "\nData akun tidak ada!!" << endl;
    return false;
  }else{
    // kalo ada datanya
    dataAkun[index].username = "";
    dataAkun[index].password = "";
    return true;
  }
  
}


// print Data Akun
void printDataAkun()
{
  cout << "\nData Akun : " << endl;
  cout << "| Index\t - Username - Password |" << endl;
  for( int i = 0; i < 26; i++ ){
    cout << "| " << i << "\t - ";
    if( dataAkun[i].username == "" ){
      cout << "(kosong) - ";
    }else{
      cout << dataAkun[i].username << " - ";
    }
    if( dataAkun[i].password == "" ){
      cout << "(kosong) |" << endl;
    }else{
      cout << dataAkun[i].password << " |" << endl;
    }
  }
}


// view Daftar
void viewDaftar()
{
  string username, password;
  cout << "\n== MENU DAFTAR ==" << endl;
  cout << "Masukkan username & password" << endl;
  cout << "Isi Username anda : ";
  cin >> username;
  cout << "Isi Password anda : ";
  cin >> password;

  if( cekDaftar(username, password) ){
    cout << "Akun berhasil terdaftar!!" << endl;
  }else{
    cout << "Akun gagal terdaftar!!" << endl;
  }
  
}

// view Tambah Akun
void viewTambahAkun()
{
  
  string username, password;
  cout << "\n== MENU TAMBAH AKUN ==" << endl;
  cout << "Masukkan username & password" << endl;
  cout << "Isi Username akun : ";
  cin >> username;
  cout << "Isi Password akun : ";
  cin >> password;

  if( cekDaftar(username, password) ){
    cout << "Akun berhasil terdaftar!!" << endl;
  }else{
    cout << "Akun gagal terdaftar!!" << endl;
  }
  

}

// viewHapusAkun
void viewHapusAkun()
{
  int index;
  cout << "\n== MENU HAPUS AKUN ==" << endl;
  cout << "Isi index : ";
  cin >> index;

  if( cekHapusAkun(index) ){
    cout << "Data akun berhasil dihapus!!" << endl;
  }else{
    cout << "Data akun gagal dihapus!!" << endl;
  }

}

// view Menu Login
void viewMenuLogin()
{
  while( true ){
    string pilihan;
    cout << "\n== MENU ADMIN ==" << endl;
    cout << "Menu Pilihan :" << endl;
    cout << "1. Tambah Akun" << endl;
    cout << "2. Hapus Akun" << endl;
    cout << "3. Lihat Data Akun" << endl;
    cout << "4. Logout" << endl;
    cout << "Pilih menu [1/2/3] : ";
    cin >> pilihan;
    if( pilihan == "1" ){
      viewTambahAkun();
    }else if( pilihan == "2" ){
      viewHapusAkun();
    }else if( pilihan == "3" ){
      printDataAkun();
    }else if( pilihan == "4" ){
      cout << "Anda berhasil logout" << endl;
      break;
    }else{
      cout << "Pilihan tidak tersedia!!" << endl;
    }
  }
}

// view Login
void viewLogin()
{
  string username, password;
  cout << "== VIEW LOGIN ==" << endl;
  cout << "Masukkan username & password" << endl;
  cout << "Isi username anda : ";
  cin >> username;
  cout << "Isi password anda : ";
  cin >> password;

  if( cekLogin(username, password) ){
    cout << "\nLogin berhasil!!" << endl;
    viewMenuLogin();
  }else{
    cout << "\nLogin Gagal!!" << endl;
  }
  
}


// tampilan utama
void welcome()
{
  while( true ){
    string pilihan;
    cout << "\n\n== PROGRAM LOGIN SEDERHANA DENGAN HASHING ==" << endl;
    cout << "Menu Pilihan :" << endl;
    cout << "1. Daftar" << endl;
    cout << "2. Login" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih menu [1/2/3] : ";
    cin >> pilihan;

    if( pilihan == "1" ){
      viewDaftar();
    }else if( pilihan == "2" ){
      viewLogin();
    }else if( pilihan == "3" ){
      cout << "\nTerimakasih sudah menggunakan aplikasi login sederhana." << endl;
      break;
    }else{
      cout << "Pilihan tidak tersedia!!" << endl;
    }
  }
  
}


int main()
{

  welcome();
  

}
