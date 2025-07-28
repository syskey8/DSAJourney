#include <iostream>
#include <cmath>
using namespace std;

int count_no_of_digits(int n) { // counts the number of digits
  if (n == 0) {
    return 1;
  }
  
  int count = 0;

  while (n > 0) {
    n /= 10;
    ++count;
  }

  return count;
}

int sum_of_digits(int n) { // reutrns sum of digits
  int c, quotient, remainder, dividend, divisor;
  int sum = 0;

  c = count_no_of_digits(n);

  if(c != 1) {
    divisor = pow(10, (c - 1));
  }
  else {
    divisor = 1;
  }

  dividend = n;

  for(int i = 1; i <= c; i++) {
    quotient = dividend / divisor;
    remainder = dividend % divisor;
    sum += quotient;
    dividend = remainder;
    divisor = divisor / 10; 
  }

  return sum;
}

int main () {
  int n;

  cout << "Enter a number: " << endl;
  cin >> n;

  cout << "Sum: " << sum_of_digits(n) << endl;
}
