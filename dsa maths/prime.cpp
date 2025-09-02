// there is a better appraoch called sieve of erathosthenes

#include <iostream>
using namespace std;

string isPrime(int n)
{
    for (int i = 2; i * i < n; i++) // the loop mathematically need to run from 2 to root of n
    {
        if (n % i == 0)
        {
            return "Non Prime";
        }
    }

    return "Prime";
}

int main()
{
    int n = 42;
    cout << isPrime(n) << endl;

    return 0;
}