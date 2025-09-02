// there is an better approach to find GCD, euclid's algorithm
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int gcd = 1;
    for (int i = 1; i <= min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0) // this is brute force approach
        {
            gcd = i;
        }
    }

    return gcd;
}

int main()
{
    int a = 12, b = 18;
    cout << gcd(a, b) << endl;
}