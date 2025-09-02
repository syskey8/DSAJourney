#include <iostream>
using namespace std;

bool armstrong(int n)
{
    int copyN = n;
    int sum = 0;
    while (n != 0)
    {
        int digit = n % 10;
        sum = sum + (digit * digit * digit);

        n = n / 10;
    }

    return sum == copyN;
}

int main()
{
    int n = 153;

    if (armstrong(n))
    {
        cout << "Is an Armstrong Number" << endl;
    }
    else
    {
        cout << "Is not an Armstrong Number" << endl;
    }
}