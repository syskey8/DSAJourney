// sum of numbers divisble by 3

#include <iostream>
using namespace std;

int main () {
  int n;
  int sum = 0;

  cout << "Enter the value of n: " << endl;
  cin >> n;

  for(int i = 1; i <= n; i++) {
    if(i % 3 == 0) {
      sum += i;
    }
  }

  cout << "Sum: " << sum << endl;

  return 0;
}
