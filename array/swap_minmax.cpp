// WAF to swap the max and min number of an array

#include <iostream>
#include <climits>
using namespace std;

int main () {
  int nums[] = {5, 15, 22, 1, -15, 24};
  int size = 6;
  int smallest_index, largest_index;
  int smallest = INT_MAX;
  int largest = INT_MIN;
  
  for (int i = 0; i < size; i++) {
    if (nums[i] < smallest) {
      smallest = nums[i];
      smallest_index = i;
    }
    if (nums[i] > largest) {
      largest = nums[i];
      largest_index = i;
    }   
  }
  
  cout << "Smallest: " << smallest << endl;
  cout << "Largest: " << largest << endl;
  
  swap(nums[smallest_index], nums[largest_index]);

  for (int i = 0; i < size; i++) {
    cout << nums[i] << " " << endl;
  }

  return 0;
}
