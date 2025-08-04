#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currentSum = 0;   // Running sum of current subarray
        int maxSum = INT_MIN; // Maximum sum found so far (start with smallest possible)

        for (int val : nums)
        {
            currentSum += val;                // Add current element to running sum
            maxSum = max(currentSum, maxSum); // Update max if current sum is better

            // If current sum becomes negative, reset it to 0
            // (starting fresh is better than carrying negative sum)
            if (currentSum < 0)
            {
                currentSum = 0;
            }
        }

        return maxSum;
    }
};

// Example usage:

int main()
{
    Solution solution;

    // Test case 1: [-2,1,-3,4,-1,2,1,-5,4] -> Expected output: 6 (subarray [4,-1,2,1])
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Test 1 - Max subarray sum: " << solution.maxSubArray(nums1) << endl;

    // Test case 2: [1] -> Expected output: 1
    vector<int> nums2 = {1};
    cout << "Test 2 - Max subarray sum: " << solution.maxSubArray(nums2) << endl;

    // Test case 3: [5,4,-1,7,8] -> Expected output: 23 (entire array)
    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << "Test 3 - Max subarray sum: " << solution.maxSubArray(nums3) << endl;

    // Test case 4: [-2,-1] -> Expected output: -1 (all negative numbers)
    vector<int> nums4 = {-2, -1};
    cout << "Test 4 - Max subarray sum: " << solution.maxSubArray(nums4) << endl;

    // Test case 5: [-1,0,-2] -> Expected output: 0
    vector<int> nums5 = {-1, 0, -2};
    cout << "Test 5 - Max subarray sum: " << solution.maxSubArray(nums5) << endl;

    return 0;
}

/*
KADANE'S ALGORITHM EXPLANATION:
The key insight is that at any point, we have two choices:
1. Extend the existing subarray by including the current element
2. Start a new subarray from the current element

We choose option 2 (reset currentSum to 0) when the running sum becomes negative,
because any negative sum would only decrease the total of future elements.

Example walkthrough with [-2,1,-3,4,-1,2,1,-5,4]:
- Start: currentSum=0, maxSum=INT_MIN
- -2: currentSum=-2, maxSum=-2, reset currentSum=0
- 1:  currentSum=1, maxSum=1
- -3: currentSum=-2, maxSum=1, reset currentSum=0
- 4:  currentSum=4, maxSum=4
- -1: currentSum=3, maxSum=4
- 2:  currentSum=5, maxSum=5
- 1:  currentSum=6, maxSum=6
- -5: currentSum=1, maxSum=6
- 4:  currentSum=5, maxSum=6
Final answer: 6
*/