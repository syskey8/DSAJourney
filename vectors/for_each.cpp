#include <iostream>
#include <vector>

using namespace std;

int main () {
  vector<char> vec = {'a', 'b', 'c', 'd', 'e'};

  for(char val : vec) { // val is not the index, it is the value
    cout << val << endl;
  }
}
