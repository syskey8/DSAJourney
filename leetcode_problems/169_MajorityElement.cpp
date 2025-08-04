#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();

        int freq = 0;      // Frequency counter for current candidate
        int ans = nums[0]; // Current candidate for majority element

        for (int i = 0; i < n; i++)
        {
            // If frequency becomes 0, select new candidate
            if (freq == 0)
            {
                ans = nums[i];
            }

            // If current element matches candidate, increment frequency
            if (ans == nums[i])
            {
                freq++;
            }
            // If current element is different, decrement frequency
            else
            {
                freq--;
            }
        }

        return ans; // Return the majority element
    }
};

// Example usage:

int main()
{
    Solution solution;

    // Test case 1: [3,2,3] -> Expected output: 3
    vector<int> nums1 = {3, 2, 3};
    cout << "Test 1 - Majority element: " << solution.majorityElement(nums1) << endl;

    // Test case 2: [2,2,1,1,1,2,2] -> Expected output: 2
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Test 2 - Majority element: " << solution.majorityElement(nums2) << endl;

    // Test case 3: [1] -> Expected output: 1
    vector<int> nums3 = {1};
    cout << "Test 3 - Majority element: " << solution.majorityElement(nums3) << endl;

    // Test case 4: [6,5,5] -> Expected output: 5
    vector<int> nums4 = {6, 5, 5};
    cout << "Test 4 - Majority element: " << solution.majorityElement(nums4) << endl;

    // Test case 5: [1,1,2,2,2] -> Expected output: 2
    vector<int> nums5 = {1, 1, 2, 2, 2};
    cout << "Test 5 - Majority element: " << solution.majorityElement(nums5) << endl;

    return 0;
}

/*
BOYER-MOORE MAJORITY VOTE ALGORITHM EXPLANATION:
This algorithm finds the majority element (appears > n/2 times) in O(n) time and O(1) space.

Key insight: If we cancel out each occurrence of an element e with all the other
elements that are different from e, then e will exist till the end if it is a majority element.

Example walkthrough with [2,2,1,1,1,2,2]:
- Start: freq=0, ans=undefined
- 2: freq=0 so ans=2, freq=1
- 2: ans==2 so freq=2
- 1: ans!=1 so freq=1
- 1: ans!=1 so freq=0
- 1: freq=0 so ans=1, freq=1
- 2: ans!=2 so freq=0
- 2: freq=0 so ans=2, freq=1
Final answer: 2

The algorithm works because the majority element appears more than n/2 times,
so even after all cancellations, it will survive as the final candidate.
*/