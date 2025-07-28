#include <iostream>
using namespace std;

int reverseArray(int arr[], int size) {
  int start = 0, end = size - 1;

  while (start <= end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }

  return 0;
}

int main() {
  int arr[] = {4, 3, 7, 8, 12, 1};
  int size = 6;

  reverseArray(arr, size);

  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
