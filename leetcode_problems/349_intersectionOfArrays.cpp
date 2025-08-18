#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    // Your original solution (works correctly but can be optimized)
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        int n = nums1.size(), m = nums2.size();

        // Check each element in nums1 against all elements in nums2
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    // Found a match, check if it's already in result
                    if (ans.empty())
                    {
                        ans.push_back(nums1[i]);
                    }
                    else
                    {
                        // Check if element already exists in result array
                        if (find(ans.begin(), ans.end(), nums1[i]) == ans.end())
                        {
                            ans.push_back(nums1[i]);
                        }
                    }
                }
            }
        }
        return ans;
    }

    // Optimized solution using hash set
    vector<int> intersectionOptimized(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1(nums1.begin(), nums1.end()); // Convert nums1 to set
        unordered_set<int> resultSet;                        // Store unique intersections

        // Check each element in nums2
        for (int num : nums2)
        {
            if (set1.count(num))
            {                          // If num exists in nums1
                resultSet.insert(num); // Add to result set (automatically handles duplicates)
            }
        }

        // Convert set back to vector
        return vector<int>(resultSet.begin(), resultSet.end());
    }
};

// Example usage:

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

    // Test case 1: nums1=[1,2,2,1], nums2=[2,2] -> Expected output: [2]
    vector<int> nums1_1 = {1, 2, 2, 1};
    vector<int> nums2_1 = {2, 2};
    cout << "Test 1 - nums1: [1,2,2,1], nums2: [2,2]" << endl;
    cout << "Original solution: ";
    vector<int> result1 = solution.intersection(nums1_1, nums2_1);
    printVector(result1);
    cout << "Optimized solution: ";
    vector<int> result1_opt = solution.intersectionOptimized(nums1_1, nums2_1);
    printVector(result1_opt);
    cout << endl;

    // Test case 2: nums1=[4,9,5], nums2=[9,4,9,8,4] -> Expected output: [9,4] or [4,9]
    vector<int> nums1_2 = {4, 9, 5};
    vector<int> nums2_2 = {9, 4, 9, 8, 4};
    cout << "Test 2 - nums1: [4,9,5], nums2: [9,4,9,8,4]" << endl;
    cout << "Original solution: ";
    vector<int> result2 = solution.intersection(nums1_2, nums2_2);
    printVector(result2);
    cout << "Optimized solution: ";
    vector<int> result2_opt = solution.intersectionOptimized(nums1_2, nums2_2);
    printVector(result2_opt);
    cout << endl;

    // Test case 3: nums1=[1,2,3], nums2=[4,5,6] -> Expected output: []
    vector<int> nums1_3 = {1, 2, 3};
    vector<int> nums2_3 = {4, 5, 6};
    cout << "Test 3 - nums1: [1,2,3], nums2: [4,5,6]" << endl;
    cout << "Original solution: ";
    vector<int> result3 = solution.intersection(nums1_3, nums2_3);
    printVector(result3);
    cout << "Optimized solution: ";
    vector<int> result3_opt = solution.intersectionOptimized(nums1_3, nums2_3);
    printVector(result3_opt);
    cout << endl;

    return 0;
}

/*
ALGORITHM COMPARISON:

Your Original Solution:
- Time Complexity: O(n*m*k) where k is result size (due to find() operation)
- Space Complexity: O(k) for result array
- Approach: Nested loops with linear search for duplicates

Optimized Solution:
- Time Complexity: O(n+m)
- Space Complexity: O(n+m) for hash sets
- Approach: Hash set for O(1) lookups and automatic duplicate handling

Both solutions are correct, but the optimized version is much faster for larger inputs.
The order of elements in the result may vary between approaches since hash sets don't
maintain insertion order.

Key improvements in optimized version:
1. Use hash set for O(1) element lookup instead of O(k) linear search
2. Use set to automatically handle duplicates instead of manual checking
3. Single pass through nums2 instead of nested loops

Your original solution demonstrates good understanding of the problem and
handles edge cases correctly!
*/