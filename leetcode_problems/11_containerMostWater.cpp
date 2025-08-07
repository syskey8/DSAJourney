#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1; // Two pointers at start and end
        int currWater, maxWater = 0;             // Current and maximum water area

        while (left < right)
        {
            // Calculate current water area: width × min(left_height, right_height)
            currWater = (right - left) * min(height[left], height[right]);

            // Update maximum water area if current is larger
            maxWater = max(maxWater, currWater);

            // Move the pointer with smaller height inward
            // (moving the taller one would only decrease the area)
            height[left] < height[right] ? left++ : right--;
        }

        return maxWater;
    }
};

int main()
{
    Solution solution;

    // Test case 1: [1,8,6,2,5,4,8,3,7] -> Expected output: 49
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test 1 - Heights: [1,8,6,2,5,4,8,3,7], Max area: "
         << solution.maxArea(height1) << endl;

    // Test case 2: [1,1] -> Expected output: 1
    vector<int> height2 = {1, 1};
    cout << "Test 2 - Heights: [1,1], Max area: "
         << solution.maxArea(height2) << endl;

    // Test case 3: [4,3,2,1,4] -> Expected output: 16
    vector<int> height3 = {4, 3, 2, 1, 4};
    cout << "Test 3 - Heights: [4,3,2,1,4], Max area: "
         << solution.maxArea(height3) << endl;

    // Test case 4: [1,2,1] -> Expected output: 2
    vector<int> height4 = {1, 2, 1};
    cout << "Test 4 - Heights: [1,2,1], Max area: "
         << solution.maxArea(height4) << endl;

    // Test case 5: [2,3,4,5,18,17,6] -> Expected output: 17
    vector<int> height5 = {2, 3, 4, 5, 18, 17, 6};
    cout << "Test 5 - Heights: [2,3,4,5,18,17,6], Max area: "
         << solution.maxArea(height5) << endl;

    return 0;
}

/*
TWO-POINTER ALGORITHM EXPLANATION:
The key insight is that we want to maximize: width × min(left_height, right_height)

Why move the shorter line?
- The water level is limited by the shorter line
- Moving the taller line inward would only decrease width while keeping the same water level
- Moving the shorter line gives us a chance to find a taller line and increase water level
- Even if the new line is shorter, we might find a better combination later

Example walkthrough with [1,8,6,2,5,4,8,3,7]:
- left=0, right=8: area = 8 × min(1,7) = 8 × 1 = 8, move left (height[0]=1 < height[8]=7)
- left=1, right=8: area = 7 × min(8,7) = 7 × 7 = 49, move right (height[1]=8 > height[8]=7)
- left=1, right=7: area = 6 × min(8,3) = 6 × 3 = 18, move right (height[1]=8 > height[7]=3)
- ... continue until left >= right
Maximum area found: 49

Time Complexity: O(n) - single pass with two pointers
Space Complexity: O(1) - only using a few variables

This is much more efficient than the brute force O(n²) approach of checking all pairs.
*/