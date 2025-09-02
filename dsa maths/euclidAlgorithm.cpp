#include <iostream>
using namespace std;

int euclid(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a == 0)
        return b;
    else
        return a;
}

/*
GCD using recursion
in this b is greater than a is considered

int gcdRec(int a, int b) {
    if(b == 0) return a;

    return gcdRec(b, a % b);
}
*/

int main()
{
    cout << euclid(20, 28) << endl;
    return 0;
}