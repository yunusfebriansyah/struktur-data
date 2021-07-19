#include <iostream>
using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct Mahasiswa{
  string npm, nama, jurusan;

  Mahasiswa *next;
};

Mahasiswa *head, *tail, *newNode, *cur, *del;

// create Circular Single Linked List
void createCircularSingleLinkedList(string dataBaru[3]){

  head = new Mahasiswa();
  head->npm = dataBaru[0];
  head->nama = dataBaru[1];
  head->jurusan = dataBaru[2];
  tail = head;
  tail->next = head;

}

// add first
void addFirst( string data[3] ){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    newNode = new Mahasiswa();
    newNode->npm = data[0];
    newNode->nama = data[1];
    newNode->jurusan = data[2];
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}

// add Last
void addLast( string data[3] ){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    newNode = new Mahasiswa();
    newNode->npm = data[0];
    newNode->nama = data[1];
    newNode->jurusan = data[2];
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}

// add Middle
void addMiddle(string data[3], int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi satu bukan posisi tengah!!!" << endl;
    }else{
      newNode = new Mahasiswa();
      newNode->npm = data[0];
      newNode->nama = data[1];
      newNode->jurusan = data[2];

      // tranversing
      int nomor = 1;
      cur = head;
      while (nomor < posisi - 1)
      {
        cur = cur->next;
        nomor++;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}

// remove First
void removeFirst(){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    delete del;
  }
}

// remove last
void removeLast()
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    del = tail;
    cur = head;
    while( cur->next != tail ){
      cur = cur->next;
    }
    tail = cur;
    tail->next = head;
    delete del;
  }
}

// remove middle
void removeMiddle(int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    // tranversing
    int nomor = 1;
    cur = head;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    del = cur->next;
    cur->next = del->next;
    delete del;
  }
}


void printCircular()
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    cout << "Data Mahasiswa " << endl;
    cout << "________________________________________________________________" << endl; 
    cout << "| NPM\t\t| Nama\t\t\t| Jurusan\t\t|" << endl;
    cout << "________________________________________________________________" << endl; 
    cur = head;
    while (cur->next != head)
    {
      // print
      cout << "| " << cur->npm << "\t| " << cur->nama << "\t| " << cur->jurusan << "\t\t|" << endl;
      cur = cur->next;
    }
    cout << "| " << cur->npm << "\t| " << cur->nama << "\t| " << cur->jurusan << "\t\t|" << endl;
    cout << "_________________________________________________________________" << endl;
  }
}


int main(){
  string dataBaru[3] = {"19312009", "Yunus Febriansyah", "Informatika"};
  createCircularSingleLinkedList(dataBaru);

  printCircular();

  string data[3] = {"19312079", "M Rizky Fadhilah", "Informatika"};
  addFirst(data);

  printCircular();

  string data2[3] = {"19312015", "Gilang Ramadan", "Sistem Informasi"};
  addLast(data2);

  printCircular();

  string data3[3] = {"19312024", "Verdian Galang", "Teknik Elektro"};
  addMiddle(data3, 5);

  printCircular();

  removeMiddle(6);

  printCircular();

  removeFirst();

  printCircular();

  removeLast();

  printCircular();
}

