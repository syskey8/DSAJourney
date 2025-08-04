#include <iostream>
#include <iomanip>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        // Base cases for quick returns
        if (n == 0)
            return 1.0; // Any number to power 0 is 1
        if (x == 0)
            return 0.0; // 0 to any power is 0
        if (x == 1)
            return 1.0; // 1 to any power is 1
        if (x == -1 && n % 2 == 0)
            return 1.0; // (-1)^even = 1
        if (x == -1 && n % 2 != 0)
            return -1.0; // (-1)^odd = -1

        // Handle negative exponents
        long binForm = n; // Use long to avoid overflow when negating INT_MIN
        if (n < 0)
        {
            x = 1 / x;          // x^(-n) = (1/x)^n
            binForm = -binForm; // Make exponent positive
        }

        double ans = 1; // Result accumulator

        // Binary exponentiation algorithm
        while (binForm > 0)
        {
            // If current bit is 1, multiply current power of x to result
            if (binForm % 2 == 1)
            {
                ans *= x;
            }
            x *= x;       // Square x for next iteration
            binForm /= 2; // Move to next bit (right shift)
        }

        return ans;
    }
};

// Example usage:

int main()
{
    Solution solution;

    // Test case 1: 2^10 -> Expected output: 1024
    cout << "Test 1 - 2^10: " << solution.myPow(2.0, 10) << endl;

    // Test case 2: 2.1^3 -> Expected output: 9.261
    cout << "Test 2 - 2.1^3: " << fixed << setprecision(3) << solution.myPow(2.1, 3) << endl;

    // Test case 3: 2^(-2) -> Expected output: 0.25
    cout << "Test 3 - 2^(-2): " << solution.myPow(2.0, -2) << endl;

    // Test case 4: 1^(-2147483648) -> Expected output: 1
    cout << "Test 4 - 1^(-2147483648): " << solution.myPow(1.0, -2147483648) << endl;

    // Test case 5: (-2)^3 -> Expected output: -8
    cout << "Test 5 - (-2)^3: " << solution.myPow(-2.0, 3) << endl;

    // Test case 6: 0^5 -> Expected output: 0
    cout << "Test 6 - 0^5: " << solution.myPow(0.0, 5) << endl;

    // Test case 7: 3^0 -> Expected output: 1
    cout << "Test 7 - 3^0: " << solution.myPow(3.0, 0) << endl;

    return 0;
}

/*
BINARY EXPONENTIATION ALGORITHM EXPLANATION:
Instead of multiplying x by itself n times (O(n)), we use the binary representation
of n to reduce the time complexity to O(log n).

Key insight: x^n can be computed by breaking n into powers of 2.
For example: x^13 = x^8 * x^4 * x^1 (since 13 = 8 + 4 + 1 in binary: 1101)

Example walkthrough with x=3, n=10 (binary: 1010):
- Start: ans=1, x=3, binForm=10
- Bit 0 (rightmost): 10%2=0, so don't multiply ans. x=3*3=9, binForm=5
- Bit 1: 5%2=1, so ans=1*9=9. x=9*9=81, binForm=2
- Bit 2: 2%2=0, so don't multiply ans. x=81*81=6561, binForm=1
- Bit 3: 1%2=1, so ans=9*6561=59049. x=6561*6561, binForm=0
Final answer: 59049 = 3^10

The algorithm handles edge cases and negative exponents elegantly.
*/