#include <iostream>
using namespace std;

int main() {
  int n;
  int product = 1;

  cout << "Enter number: " << endl;
  cin >> n;

  for(int i = 1; i <=n; i++) {
    product *= i; 
  }

  cout << "factorial: " << product << endl;
  return 0;
}
