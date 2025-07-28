#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vec; // creates a int vector

  cout << "size = " << vec.size() << endl;
  vec.push_back(25); // add 25 to the vector
  vec.push_back(35); // then adds 35
  vec.push_back(45); // then adds 45
  vec.push_back(55); // then adds 55
  vec.push_back(65); // then adds 65
  cout << "after push back size = " << vec.size() << endl; // will show 3 because there are 3 elements in the vector
 
  for (int val : vec) {
    cout << val << endl; // prints all the elements in the vector
  } 
  vec.pop_back();
  
  cout << "after pop back size = " << vec.size() << endl; // will show 2 becuase there are 2 elements in the vector

  for (int val : vec) {
    cout << val << endl; // prints all the elements in the vector
  }

  cout << "front: " << vec.front() << endl; // this will print the first element in the vector
  cout << "back: " << vec.back() << endl; // this willl print the last element in the vector
  
  cout << "element at 2 : " << vec.at(2) << endl; // prints element at index 2
  return 0;
}
