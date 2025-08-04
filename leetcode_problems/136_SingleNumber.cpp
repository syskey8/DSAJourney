#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0; // Initialize result to 0

        // XOR all numbers together
        for (int val : nums)
        {
            ans ^= val; // XOR current number with result
        }

        return ans; // The single number that appears once
    }
};

// Example usage:

int main()
{
    Solution solution;

    // Test case 1: [2,2,1] -> Expected output: 1
    vector<int> nums1 = {2, 2, 1};
    cout << "Test 1 - Single number: " << solution.singleNumber(nums1) << endl;

    // Test case 2: [4,1,2,1,2] -> Expected output: 4
    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "Test 2 - Single number: " << solution.singleNumber(nums2) << endl;

    // Test case 3: [1] -> Expected output: 1
    vector<int> nums3 = {1};
    cout << "Test 3 - Single number: " << solution.singleNumber(nums3) << endl;

    // Test case 4: [7,3,5,4,5,3,4] -> Expected output: 7
    vector<int> nums4 = {7, 3, 5, 4, 5, 3, 4};
    cout << "Test 4 - Single number: " << solution.singleNumber(nums4) << endl;

    return 0;
}

/*
HOW IT WORKS:
The XOR operation has these key properties:
1. a ^ a = 0 (any number XORed with itself is 0)
2. a ^ 0 = a (any number XORed with 0 is the number itself)
3. XOR is commutative and associative

So when we XOR all numbers:
- All pairs cancel out to 0 (since each appears twice)
- Only the single number remains
- Example: [4,1,2,1,2] -> 4^1^2^1^2 = 4^(1^1)^(2^2) = 4^0^0 = 4
*/