#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0, end = n - 1;

        // Special case: only one element
        if (n == 1)
            return nums[0];

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            // Edge cases: check first and last element
            if (mid == 0 && nums[0] != nums[1])
                return nums[0];
            if (mid == n - 1 && nums[n - 1] != nums[n - 2])
                return nums[n - 1];

            // If current element is different from both neighbors → answer found
            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
                return nums[mid];

            // Binary search logic:
            if (mid % 2 == 0)
            {
                // mid is even
                if (nums[mid] == nums[mid - 1])
                {
                    // Pair is on the left → move left
                    end = mid - 1;
                }
                else
                {
                    // Pair is on the right → move right
                    start = mid + 1;
                }
            }
            else
            {
                // mid is odd
                if (nums[mid] == nums[mid - 1])
                {
                    // Pair is on the left → move right
                    start = mid + 1;
                }
                else
                {
                    // Pair is broken → single is on the left
                    end = mid - 1;
                }
            }
        }
        return -1; // Should never reach here if input is valid
    }
};

// ----------------------------
// Main function for testing
// ----------------------------
int main()
{
    Solution sol;

    vector<vector<int>> testCases = {
        {1, 1, 2, 3, 3, 4, 4, 8, 8}, // single element is 2
        {3, 3, 7, 7, 10, 11, 11},    // single element is 10
        {1},                         // single element is 1 (only one element)
        {0, 0, 1, 1, 2, 3, 3, 4, 4}, // single element is 2
        {5, 6, 6, 7, 7, 8, 8}        // single element is 5
    };

    for (auto &nums : testCases)
    {
        cout << "Array: ";
        for (int num : nums)
            cout << num << " ";
        cout << "\nSingle element: " << sol.singleNonDuplicate(nums) << "\n\n";
    }

    return 0;
}
