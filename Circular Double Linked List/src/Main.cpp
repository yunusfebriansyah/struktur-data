#include <iostream>

using namespace std;

// struktur linked list
struct dataBarang{
  string namaBarang;
  int jumlahBarang, hargaBarang;

  // pointer
  dataBarang *prev;
  dataBarang *next;
};

dataBarang *head, *tail, *cur, *del, *newNode, *afterNode;

// fungsi membuat circular double Linked list
void createDataBarang( string namaBarang, int jmlBarang, int hargaBarang ){
  head = new dataBarang();
  head->namaBarang = namaBarang;
  head->jumlahBarang = jmlBarang;
  head->hargaBarang = hargaBarang;
  head->prev = head;
  head->next = head;
  tail = head;
}

// add First
void addFirst( string namaBarang, int jmlBarang, int hargaBarang ){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    newNode = new dataBarang();
    newNode->namaBarang = namaBarang;
    newNode->jumlahBarang = jmlBarang;
    newNode->hargaBarang = hargaBarang;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
  }
}

// add Last
void addLast( string namaBarang, int jmlBarang, int hargaBarang ){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    newNode = new dataBarang();
    newNode->namaBarang = namaBarang;
    newNode->jumlahBarang = jmlBarang;
    newNode->hargaBarang = hargaBarang;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
  }
}

// add Middle
void addMiddle( string namaBarang, int jmlBarang, int hargaBarang, int posisi ){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi 1 bukan posisi tengah" << endl;
    }else if( posisi < 1 ){
      cout << "Posisi diluar jangkauan" << endl;
    }else{
      newNode = new dataBarang();
      newNode->namaBarang = namaBarang;
      newNode->jumlahBarang = jmlBarang;
      newNode->hargaBarang = hargaBarang;

      // tranversing
      cur = head;
      int nomor = 1;
      while ( nomor < posisi - 1 ){
        cur = cur->next;
        nomor++;
      }
      afterNode = cur->next;
      cur->next = newNode;
      afterNode->prev = newNode;
      newNode->prev = cur;
      newNode->next = afterNode;
    }
  }
}

// remove First
void removeFirst(){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    delete del;
  }
}

// remove Last
void removeLast(){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    del = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete del;
  }
}

// remove Middle
void removeMiddle(int posisi){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi 1 bukan posisi tengah" << endl;
    }else if( posisi < 1 ){
      cout << "Posisi diluar jangkauan" << endl;
    }else{
      // tranversing
      cur = head;
      int nomor = 1;
      while ( nomor < posisi - 1 ){
        cur = cur->next;
        nomor++;
      }
      del = cur->next;
      afterNode = del->next;
      cur->next = afterNode;
      afterNode->prev = cur;
      delete del;
    }
  }
}

// fungsi print
void printDataBarang()
{
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    cout << "Data Barang : " << endl;
    cur = head;
    while( cur->next != head ){
      // print
      cout << "Nama Barang : " << cur->namaBarang << endl;
      cout << "Jumlah Barang : " << cur->jumlahBarang << " barang" << endl;
      cout << "Harga Barang : Rp." << cur->hargaBarang << "\n" << endl;

      // step
      cur = cur->next;
    }
    // print last node
      cout << "Nama Barang : " << cur->namaBarang << endl;
      cout << "Jumlah Barang : " << cur->jumlahBarang << " barang" << endl;
      cout << "Harga Barang : Rp." << cur->hargaBarang << "\n" << endl;
  }
}

int main(){

  createDataBarang("Shampoo", 15, 5000);
  printDataBarang();

  addFirst("Sikat Gigi", 23, 7000);
  printDataBarang();

  addLast("Sabun Mandi", 11, 12000);
  printDataBarang();

  addMiddle("Pomade", 11, 20000, 6);
  printDataBarang();

  removeMiddle(6);
  printDataBarang();



}