// there is a better approach to this = kadane's algorithm
// this is a better brute force approach

#include <iostream>
using namespace std;

int main() {
  int size = 1;
  int maxSum = 0;
  int currentSum;
  int arr[size]; // everything is initialized
  cout << "Enter the size of the array: " << endl;
  cin >> size;
  cout << "Enter the elements: " << endl;
  for(int i = 0; i < size; i++) { // this loop takes input for all the elements of the vector
    cin >> arr[i];
  }
  
  cout << "Array = {";
  for(int i = 0; i < size; i++) { // this loop prints the loop just for showcase
    cout << arr[i];
    if (i != size - 1) {
      cout << ", ";
    }
  }
  cout << "}" << endl;

  for (int start = 0; start < size; start++) { // after every iteration the current sum is set to 0 (refer to subarray for more explantion)
    int currentSum = 0;

    for(int end = start; end < size; end++){
      currentSum += arr[end]; // adds the last element to the currentsum
      maxSum = max(currentSum, maxSum); // compares the current value and max
    }
  }
  
  cout << "Max sum : " << maxSum << endl; // prints max value
  
  return 0;
}
