#include <iostream>
using namespace std;

int main () {
  int n;
  bool isPrime = true;

  cout << "Enter you number to check prime or not : ";
  cin >> n;

  for (int i = 2; i * i <= n; i++) { // the loop only need to run untill root n as the factors repeat.
    if (n % i == 0) {
      isPrime = false;
      break;
    }
  }

  if (isPrime == true) {
    cout << "prime number" << endl;
  }
  else {
    cout << "non prime number" << endl;
  }
}
