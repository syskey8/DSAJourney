// WAF to calculate sum and product of all numbers in an array

#include <iostream>
using namespace std;

int sumAndProduct(int arr[], int size) {
  int sum = 0, product = 1;
  for(int i = 0; i < size; i++) {
    sum += arr[i];
    product *= arr[i];
  }

  cout << "Sum : " << sum << endl;
  cout << "Product: " << product << endl;

  return 0;
}

int main () {
  int arr[] = {16, 25, 2, 11, 86, 71};
  int size = 6;

  sumAndProduct(arr, size);

  return 0;
}
