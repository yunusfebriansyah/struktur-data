#include <iostream>
using namespace std;

// array Antrian
int maksimalAntrianArray = 5, front = 0, back = 0;
// ruang antrian array
string antrianAtm[5];

// isFull / cek data antrian penuh atau tidak
bool isFullArray()
{
  if( back == maksimalAntrianArray ){
    return true;
  }else{
    return false;
  }
}

// isEmpty
bool isEmptyArray()
{
  if( back == 0 ){
    return true;
  }else{
    return false;
  }
}


// enqueue / penambahan data antrian
void enqueueArray(string data){

  if( isFullArray() ){
    cout << "Antrian penuh!!" << endl;
  }else{
    // cek apakah datanya kosong atau tidak
    if( isEmptyArray() ){
      // kalau antrian kosong
      antrianAtm[0] = data;
      front++;
      back++;
    }else{
      // kalo gak kosong
      antrianAtm[back] = data;
      back++;
    }
  }

}

// dequeue / penghapusan data depan
void dequeueArray(){
  if( isEmptyArray() ){
    cout << "Antrian kosong!!" << endl;
  }else{
    for( int i = 0; i < back; i++ ){
      antrianAtm[i] = antrianAtm[i+1];
    }
    back--;
  }
}

// countArray / menghitung banyak data yg ngantri
int countArray()
{

  if( isEmptyArray() ){
    return 0;
  }else if( isFullArray() ){
    return maksimalAntrianArray;
  }else{
    return back;
  }

}

// destroy / clear
void destroyArray(){
  if( isEmptyArray() ){
    cout << "Antrian kosong!!" << endl;
  }else{
    for( int i = 0; i < maksimalAntrianArray; i++ ){
      
      if( back > 1 ){
        antrianAtm[back - 1] = "";
        back--;
      }else if( back == 1 ){
        antrianAtm[back - 1] = "";
        back = 0;
        front = 0;
      }

    }
  }
}


// Display / View
void viewArray()
{
  cout << "Jumlah data yg ngantri : " << countArray() << "data." << endl;
  cout << "Data Antrian Atm : " << endl;
  if( isEmptyArray() ){
    cout << "Antrian kosong!!" << endl;
  }else{
    for( int i = 0; i < maksimalAntrianArray; i++ ){
      // cek apakah ruang kosong atau tidak
      if( antrianAtm[i] != "" ){
        // kalau ruang tidak kosong
        cout << i+1 << ". " << antrianAtm[i] << endl;
      }else{
        // kalo kosong
        cout << i+1 << ". (kosong)" << endl;
      }
    }
  }
  cout << "\n" << endl;
}




// siapin ruang antrian
struct antrianAtmLL{
  // data / member
  string nama;
  int umur;

  // pointer next
  antrianAtmLL *next;
};

int maksimalAntrianLinkedList = 5;
antrianAtmLL *head, *tail, *cur, *del, *newNode;

// count Linked List
int countLinkedList()
{
  if( head == NULL ){
    return 0;
  }else{
    int banyak = 0;
    cur = head;
    while( cur != NULL ){
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}

// isFull Linked List
bool isFullLinkedList()
{
  if( countLinkedList() == maksimalAntrianLinkedList ){
    return true;
  }else{
    return false;
  }
}

// isEmpty Linked List
bool isEmptyLinkedList()
{
  if( countLinkedList() == 0 ){
    return true;
  }else{
    return false;
  }
}

// enqueue / penambahan
void enqueueLinkedList( string nama, int umur ){

  if( isFullLinkedList() ){
    cout << "Antrian Penuh!!!" << endl;
  }else{
    
    if( isEmptyLinkedList() ){
      head = new antrianAtmLL();
      head->nama = nama;
      head->umur = umur;
      head->next = NULL;
      tail = head;
    }else{
      newNode = new antrianAtmLL();
      newNode->nama = nama;
      newNode->umur = umur;
      newNode->next = NULL;
      tail->next = newNode;
      tail = newNode;
    }

  }

}

// dequeue Linked List
void dequeueLinkedList()
{
  if( isEmptyLinkedList() ){
    cout << "Data Antrian Kosong!!" << endl;
  }else{
    del = head;
    head = head->next;
    del->next = NULL;
    delete del;
  }
}

// destroy / clear
void clearLinkedList()
{
  if( isEmptyLinkedList() ){
    cout << "Data Antrian Kosong!!" << endl;
  }else{
    cur = head;
    while( cur != NULL ){
      del = cur;
      cur = cur->next;
      del->next = NULL;
      delete del;
    }
    head = NULL;
    tail = NULL;
  }
}



// display Linked List
void displayLinkedList()
{
  cout << "Data Antrian : " << endl;
  if( isEmptyLinkedList() ){
    cout << "Data Antrian Kosong!!" << endl;
  }else{
    cout << "Banyak data antrian : " << countLinkedList() << endl;
    cur = head;
    int nomor = 1;
    while( nomor <= maksimalAntrianLinkedList ){
      
      if( cur != NULL ){
        cout << nomor << ". " << cur->nama << " - " << cur->umur << " tahun." << endl;
        cur = cur->next;
      }else{
        cout << nomor << ". " << "(kosong)" << endl;
      }

      nomor++;
    }

  }

  cout << "\n" << endl;

}


int main()
{

  enqueueLinkedList("Joni", 19);
  displayLinkedList();

  enqueueLinkedList("Mamat", 20);
  enqueueLinkedList("Siti", 18);
  enqueueLinkedList("Bambang", 20);
  enqueueLinkedList("Rudi", 23);
  displayLinkedList();

  enqueueLinkedList("Example", 23);
  displayLinkedList();

  dequeueLinkedList();
  displayLinkedList();

  clearLinkedList();
  displayLinkedList();

  cout << countLinkedList() << endl;

}
