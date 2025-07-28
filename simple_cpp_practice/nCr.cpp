#include <iostream>
using namespace std;

int factorial(int a) {
  int factorial = 1;

  for (int i = 1; i <= a; ++i) {
    factorial *= i;
  }

  return factorial;
}

int binomial(int n, int r) {
  return (factorial(n) / (factorial(r) * factorial(n - r)));
}

int main () {
  int n, r;

  cout << "Enter the value of n: " << endl;
  cin >> n;

  cout << "Enter the value of r" << endl;
  cin >> r;

  cout << "Binomial: " << binomial(n, r) << endl;
  return 0;
}
