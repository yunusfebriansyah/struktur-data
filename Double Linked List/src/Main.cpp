#include <iostream>
using namespace std;

// deklarasi double linked list
struct DataUser{
  string nama, username, email, password;
  DataUser *prev;
  DataUser *next;
};

DataUser *head, *tail, *cur, *newNode, *del, *afterNode;

// Create Double Linked List
void createDoubleLinkedList( string data[4] ){
  head = new DataUser();
  head->nama = data[0];
  head->username = data[1];
  head->email = data[2];
  head->password = data[3];
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

// count Double Linked List
int countDoubleLinkedList()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cur = head;
    int jumlah = 0;
    while( cur != NULL ){
      jumlah++;      
      //step
      cur = cur->next;
    }
    return jumlah;
  }
}

// Add First
void addFirst( string data[4] ){
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    newNode = new DataUser();
    newNode->nama = data[0];
    newNode->username = data[1];
    newNode->email = data[2];
    newNode->password = data[3];
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

// Add Last
void addLast( string data[4] ){
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    newNode = new DataUser();
    newNode->nama = data[0];
    newNode->username = data[1];
    newNode->email = data[2];
    newNode->password = data[3];
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
  }
}

// Add Middle
void addMiddle( string data[4], int posisi ){
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{

    if( posisi == 1 ){
      cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
    }else if( posisi < 1 || posisi > countDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!!!" << endl;
    }else{
      newNode = new DataUser();
      newNode->nama = data[0];
      newNode->username = data[1];
      newNode->email = data[2];
      newNode->password = data[3];

      // tranversing
      cur = head;
      int nomor = 1;
      while( nomor <  posisi - 1){
        cur = cur->next;
        nomor++;
      }

      afterNode = cur->next;
      newNode->prev = cur;
      newNode->next = afterNode;
      cur->next = newNode;
      afterNode->prev = newNode;
    }

  }
}

// remove First
void removeFirst()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    del = head;
    head = head->next;
    head->prev = NULL;
    delete del;
  }
}

// remove Last
void removeLast()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
  }
}

// remove Middle
void removeMiddle(int posisi){
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    if( posisi == 1 || posisi == countDoubleLinkedList() ){
      cout << "Posisi bukan posisi tegah!!" << endl;
    }else if( posisi < 1 || posisi > countDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!!" << endl;
    }else{
      int nomor = 1;
      cur = head;
      while( nomor < posisi - 1 ){
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

// Print Double Linked List
void printDoubleLinkedList()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cout << "Jumlah Data : " << countDoubleLinkedList() << endl;
    cout << "Isi Data : " << endl;
    cur = head;
    while( cur != NULL ){
      // print
      cout << "Nama User : " << cur->nama << endl;
      cout << "Username User : " << cur->username << endl;
      cout << "Email User : " << cur->email << endl;
      cout << "Password User : " << cur->password << "\n" << endl;
      //step
      cur = cur->next;
    }
  }
}

int main(){

  string newData[4] = {"Yunus Febriansyah", "yuunuss", "yunus@gmail.com", "gampangAja"};
  createDoubleLinkedList(newData);

  printDoubleLinkedList();

  string data2[4] = {"Bambang", "bmb", "bambangdong@gmail.com", "dongBambang"};

  addFirst( data2 );

  printDoubleLinkedList();

  string data3[4] = {"Siti Hidayah", "sitii", "sisiti@gmail.com", "sitiAja"};

  addLast( data3 );

  printDoubleLinkedList();

  string data4[4] = {"Mamat Hermawan", "mam", "mamatHer@yahoo.com", "hermawanMamat"};
  addMiddle(data4, 3);

  printDoubleLinkedList();

  removeMiddle(2);

  printDoubleLinkedList();


}