#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1); // Initialize result array with 1s

        // First pass: Calculate prefix products
        // ans[i] will contain product of all elements before index i
        for (int i = 1; i < n; i++)
        { // Starting from the second element
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int suffix = 1; // Variable to track suffix product

        // Second pass: Calculate suffix products and multiply with prefix
        // For each position, multiply prefix product with suffix product
        for (int i = n - 2; i >= 0; i--)
        {                          // Starting from second last element
            suffix *= nums[i + 1]; // Calculate suffix product for position i
            ans[i] *= suffix;      // Multiply prefix with suffix
        }

        return ans;
    }
};

/* same solution but with worse space complexity
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        //prefix
        for(int i = 1; i < n; i++) {  // starting from the second element
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        //suffix
        for(int i = n-2; i >=0; i--) { //starting from second last element
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        for(int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};
*/

void printVector(const vector<int> &vec)
{
    cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i < vec.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main()
{
    Solution solution;

    // Test case 1: [1,2,3,4] -> Expected output: [24,12,8,6]
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = solution.productExceptSelf(nums1);
    cout << "Test 1 - Input: [1,2,3,4], Output: ";
    printVector(result1);

    // Test case 2: [-1,1,0,-3,3] -> Expected output: [0,0,9,0,0]
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = solution.productExceptSelf(nums2);
    cout << "Test 2 - Input: [-1,1,0,-3,3], Output: ";
    printVector(result2);

    // Test case 3: [2,3,4,5] -> Expected output: [60,40,30,24]
    vector<int> nums3 = {2, 3, 4, 5};
    vector<int> result3 = solution.productExceptSelf(nums3);
    cout << "Test 3 - Input: [2,3,4,5], Output: ";
    printVector(result3);

    // Test case 4: [1,0] -> Expected output: [0,1]
    vector<int> nums4 = {1, 0};
    vector<int> result4 = solution.productExceptSelf(nums4);
    cout << "Test 4 - Input: [1,0], Output: ";
    printVector(result4);

    return 0;
}

/*
ALGORITHM EXPLANATION:
The key insight is that for each position i, the result should be:
result[i] = (product of all elements to the left of i) × (product of all elements to the right of i)

We achieve this in two passes:

Pass 1 (Prefix): Calculate left products
- ans[0] = 1 (no elements to the left)
- ans[1] = nums[0]
- ans[2] = nums[0] × nums[1]
- ans[3] = nums[0] × nums[1] × nums[2]

Pass 2 (Suffix): Calculate right products and multiply with left products
- For i=2: suffix = nums[3], ans[2] *= suffix
- For i=1: suffix = nums[2] × nums[3], ans[1] *= suffix
- For i=0: suffix = nums[1] × nums[2] × nums[3], ans[0] *= suffix

Example with [1,2,3,4]:
After prefix pass:  ans = [1, 1, 2, 6]
After suffix pass:  ans = [24, 12, 8, 6]

Time Complexity: O(n) - two passes through the array
Space Complexity: O(1) - only using the output array and one variable (suffix)
*/