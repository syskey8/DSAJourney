#include <iostream>
using namespace std;

int main() {
  int size = 1;
  int arr[size];
  cout << "Enter the size of the array: " << endl;
  cin >> size;
  cout << "Enter the elements: " << endl;
  for(int i = 0; i < size; i++) {
    cin >> arr[i];
  }
  
  cout << "Array = {";
  for(int i = 0; i < size; i++) {
    cout << arr[i];
    if (i != size - 1) {
      cout << ", ";
    }
  }
  cout << "}" << endl;

  for (int start = 0; start < size; start++) {
    for(int end = start; end < size; end++){
      for(int i = start; i <=end; i++) {
        cout << arr[i];
      }
      cout << " ";
    }
    cout << endl;
  }

  return 0;
}
