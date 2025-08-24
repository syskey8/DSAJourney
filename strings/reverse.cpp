#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "apna college";
    reverse(str.begin(), str.end()); // iterators
    cout << str << endl;
    return 0;

    /*
    for character array

    start = 0, end = n - 1;

    while (start < end) {
        swap(str[start++], str[end++]);
    }

    */
}