#include <iostream>
using namespace std;

int digits(int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return n;
}

int main()
{
    cout << "sum of digits: " << digits(234231) << endl;
    return 0;
}