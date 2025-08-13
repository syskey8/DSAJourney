#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &A, int m, vector<int> &B, int n)
    {
        int index = m + n - 1; // Start filling from the end of A
        int i = m - 1;         // Pointer for last element in A's original part
        int j = n - 1;         // Pointer for last element in B

        // Compare elements from the end and place the larger one at the back
        while (i >= 0 && j >= 0)
        { // Fixed: && instead of &
            if (A[i] >= B[j])
            {
                A[index] = A[i]; // Place A[i] at current position
                index--;
                i--;
            }
            else
            {
                A[index] = B[j]; // Place B[j] at current position
                index--;
                j--;
            }
        }

        // If there are remaining elements in B, copy them
        // (No need to copy remaining A elements as they're already in place)
        while (j >= 0)
        {
            A[index--] = B[j--];
        }
    }
};

// Example usage:

void printVector(const vector<int> &vec, int size)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << vec[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main()
{
    Solution solution;

    // Test case 1: A=[1,2,3,0,0,0], m=3, B=[2,5,6], n=3
    // Expected output: [1,2,2,3,5,6]
    vector<int> A1 = {1, 2, 3, 0, 0, 0};
    vector<int> B1 = {2, 5, 6};
    cout << "Test 1 - Before merge:" << endl;
    cout << "A: ";
    printVector(A1, 6);
    cout << "B: ";
    printVector(B1, 3);
    solution.merge(A1, 3, B1, 3);
    cout << "After merge: ";
    printVector(A1, 6);
    cout << endl;

    // Test case 2: A=[1], m=1, B=[], n=0
    // Expected output: [1]
    vector<int> A2 = {1};
    vector<int> B2 = {};
    cout << "Test 2 - Before merge:" << endl;
    cout << "A: ";
    printVector(A2, 1);
    cout << "B: ";
    printVector(B2, 0);
    solution.merge(A2, 1, B2, 0);
    cout << "After merge: ";
    printVector(A2, 1);
    cout << endl;

    // Test case 3: A=[0], m=0, B=[1], n=1
    // Expected output: [1]
    vector<int> A3 = {0};
    vector<int> B3 = {1};
    cout << "Test 3 - Before merge:" << endl;
    cout << "A: ";
    printVector(A3, 1);
    cout << "B: ";
    printVector(B3, 1);
    solution.merge(A3, 0, B3, 1);
    cout << "After merge: ";
    printVector(A3, 1);
    cout << endl;

    // Test case 4: A=[4,5,6,0,0,0], m=3, B=[1,2,3], n=3
    // Expected output: [1,2,3,4,5,6]
    vector<int> A4 = {4, 5, 6, 0, 0, 0};
    vector<int> B4 = {1, 2, 3};
    cout << "Test 4 - Before merge:" << endl;
    cout << "A: ";
    printVector(A4, 6);
    cout << "B: ";
    printVector(B4, 3);
    solution.merge(A4, 3, B4, 3);
    cout << "After merge: ";
    printVector(A4, 6);
    cout << endl;

    return 0;
}

/*
MERGE ALGORITHM EXPLANATION:
The key insight is to work backwards from the end of array A to avoid overwriting
elements that haven't been processed yet.

Why work backwards?
- Array A has enough space at the end to hold all elements
- By filling from the back, we never overwrite unprocessed elements
- We always place the larger element at the current position

Example walkthrough with A=[1,2,3,0,0,0], B=[2,5,6]:
Initial: i=2, j=2, index=5
- A[2]=3, B[2]=6: 6>3, so A[5]=6, j=1, index=4
- A[2]=3, B[1]=5: 5>3, so A[4]=5, j=0, index=3
- A[2]=3, B[0]=2: 3>2, so A[3]=3, i=1, index=2
- A[1]=2, B[0]=2: 2==2, so A[2]=2 (A[i]), i=0, index=1
- A[0]=1, B[0]=2: 2>1, so A[1]=2, j=-1, index=0
- j<0, exit main loop
- No remaining elements in B to copy
Final result: [1,2,2,3,5,6]

Edge cases handled:
1. B is empty (n=0): No merge needed
2. A's original part is empty (m=0): Copy all of B to A
3. All elements in A are larger than B: B gets copied first
4. All elements in B are larger than A: A stays in place, B fills the end

Time Complexity: O(m+n) - single pass through both arrays
Space Complexity: O(1) - in-place merge using existing space in A
*/