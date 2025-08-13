#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    { // O(n) time complexity
        int n = nums.size();
        int mid = 0;      // Pointer for current element being processed
        int high = n - 1; // Pointer for the end of unsorted region (2s go here)
        int low = 0;      // Pointer for the start of unsorted region (0s go here)

        // Dutch National Flag Algorithm
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                // Found 0: swap with low and move both low and mid forward
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
            else if (nums[mid] == 1)
            {
                // Found 1: it's already in correct position, just move mid forward
                mid++;
            }
            else
            { // nums[mid] == 2
                // Found 2: swap with high and move high backward
                // Don't increment mid because we need to check the swapped element
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};

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

    // Test case 1: [2,0,2,1,1,0] -> Expected output: [0,0,1,1,2,2]
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    cout << "Test 1 - Before: ";
    printVector(nums1);
    solution.sortColors(nums1);
    cout << "Test 1 - After:  ";
    printVector(nums1);
    cout << endl;

    // Test case 2: [2,0,1] -> Expected output: [0,1,2]
    vector<int> nums2 = {2, 0, 1};
    cout << "Test 2 - Before: ";
    printVector(nums2);
    solution.sortColors(nums2);
    cout << "Test 2 - After:  ";
    printVector(nums2);
    cout << endl;

    // Test case 3: [0] -> Expected output: [0]
    vector<int> nums3 = {0};
    cout << "Test 3 - Before: ";
    printVector(nums3);
    solution.sortColors(nums3);
    cout << "Test 3 - After:  ";
    printVector(nums3);
    cout << endl;

    // Test case 4: [1,2,0] -> Expected output: [0,1,2]
    vector<int> nums4 = {1, 2, 0};
    cout << "Test 4 - Before: ";
    printVector(nums4);
    solution.sortColors(nums4);
    cout << "Test 4 - After:  ";
    printVector(nums4);
    cout << endl;

    // Test case 5: [2,2,2,0,0,0,1,1] -> Expected output: [0,0,0,1,1,2,2,2]
    vector<int> nums5 = {2, 2, 2, 0, 0, 0, 1, 1};
    cout << "Test 5 - Before: ";
    printVector(nums5);
    solution.sortColors(nums5);
    cout << "Test 5 - After:  ";
    printVector(nums5);
    cout << endl;

    return 0;
}

/*
DUTCH NATIONAL FLAG ALGORITHM EXPLANATION:
This algorithm partitions the array into three sections:
- [0...low-1]: All 0s
- [low...mid-1]: All 1s
- [mid...high]: Unsorted (being processed)
- [high+1...n-1]: All 2s

The invariants maintained:
1. nums[0...low-1] contains only 0s
2. nums[low...mid-1] contains only 1s
3. nums[high+1...n-1] contains only 2s
4. nums[mid...high] is the unsorted region

Example walkthrough with [2,0,2,1,1,0]:
Initial: low=0, mid=0, high=5, array=[2,0,2,1,1,0]

Step 1: nums[0]=2, swap with nums[5]=0, high=4
        Array=[0,0,2,1,1,2], low=0, mid=0, high=4

Step 2: nums[0]=0, swap with nums[0]=0, low=1, mid=1
        Array=[0,0,2,1,1,2], low=1, mid=1, high=4

Step 3: nums[1]=0, swap with nums[1]=0, low=2, mid=2
        Array=[0,0,2,1,1,2], low=2, mid=2, high=4

Step 4: nums[2]=2, swap with nums[4]=1, high=3
        Array=[0,0,1,1,2,2], low=2, mid=2, high=3

Step 5: nums[2]=1, mid=3
        Array=[0,0,1,1,2,2], low=2, mid=3, high=3

Step 6: nums[3]=1, mid=4
        Array=[0,0,1,1,2,2], low=2, mid=4, high=3

mid > high, so we're done!
Final result: [0,0,1,1,2,2]

Time Complexity: O(n) - single pass
Space Complexity: O(1) - in-place sorting
*/