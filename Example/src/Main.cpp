#include <iostream>
using namespace std;

int main()
{
  int arr[5] = {1,2,3,4,5};
  cout << sizeof(arr) / sizeof(arr[0]) << endl;
}