#include <iostream>
#include <climits>
using namespace std;

int main () {
  int nums[] = {5, 15, 22, 1, -15, 24};
  int size = 6;

  int smallest = INT_MAX;

  for (int i = 0; i < size; i++) {
    if (nums[i] < smallest) {
      smallest = nums[i];
    }

    /* we can achieve the above result using min function instead of writing the whole if statement
     *
     * smallest = min(nums[i], smallest);
     *
    */
  
  }
  
  cout << "Smallest: " << smallest << endl;

  return 0;
}
