#include <iostream>
using namespace std;

void changeA(int *ptr)
{ // pass by reference using pointers
    *ptr = 20;
}

void changeA2(int &b)
{ // pass by reference using alias
    b = 30;
}

int main()
{
    int a = 10;
    cout << &a << endl;

    int *ptr = &a; // this creates a pointer variable and stores the address of a, the address of ptr will be different but it will store the address of a
    cout << ptr << endl;

    int **ptr2 = &ptr; // two starts as the first star defines the data type (pointer) second start to tell that we are creating a pointer, so this is pointer to pointer concept
    cout << ptr2 << endl;

    // Dereference Operator
    cout << *(&a) << endl;    // this goes to the address of a and then returns the value from there
    cout << *(ptr) << endl;   // this will also print the value of a due to ptr containing the address of a
    cout << *(ptr2) << endl;  // this will print the address of a
    cout << **(ptr2) << endl; // this will print the value of a

    // Pass by reference
    changeA(&a);
    cout << a << endl; // 20

    // Pass by reference using alias
    changeA2(a);
    cout << a << endl; // 30

    // array as a pointer
    int arr[] = {1, 2, 3, 4, 5}; // arr is a pointer
    cout << arr << endl;         // this will print the address of where the array starts
    cout << *arr << endl;        // this will print 0th index value

    // pointer arthimetic

    int b = 5;
    int *ptrb = &b;
    cout << ptrb << endl; // prints out the address of b
    ptrb++;               // increments the address value by the data type i.e int (4 bytes)
    cout << ptrb << endl; // +4

    ptrb + 5; // add 5 ints of memory to the address pointer

    cout << *arr << endl;
    cout << *(arr + 1) << endl;
    cout << *(arr + 2) << endl;
    cout << *(arr + 3) << endl;

    // findout distance between two pointers

    cout << ptr - ptrb << endl; // would print the distance between the two pointers (in no. of int due the data type being intergers) (this is only possible in same data type pointers)

    return 0;
}