// there is a better approach to tackle this problem
#include <iostream>
using namespace std;

int main () {
  int n;
  bool isPrime = true;

  cout << "Enter your number to check prime or not : " << endl;
  cin >> n;

  for (int i = 2; i <= n - 1; i++) {
    if (n % i == 0) {
      isPrime = false;
      break;
    }
  }

  if(isPrime == true) {
    cout << "prime number" << endl;
  }
  else {
    cout << "non prime number" << endl;
  }
}
