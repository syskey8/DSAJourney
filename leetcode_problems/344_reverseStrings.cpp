#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        int start = 0, end = n - 1; // Two pointers at beginning and end

        // Swap characters from both ends moving towards center
        while (start < end)
        {
            swap(s[start], s[end]); // Swap characters at start and end positions
            start++;                // Move start pointer forward
            end--;                  // Move end pointer backward
        }
    }
};

// Example usage:

void printCharVector(const vector<char> &vec)
{
    cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "'" << vec[i] << "'";
        if (i < vec.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

string vectorToString(const vector<char> &vec)
{
    string result;
    for (char c : vec)
    {
        result += c;
    }
    return result;
}

int main()
{
    Solution solution;

    // Test case 1: ["h","e","l","l","o"] -> Expected output: ["o","l","l","e","h"]
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    cout << "Test 1 - Before: ";
    printCharVector(s1);
    cout << "String: \"" << vectorToString(s1) << "\"" << endl;
    solution.reverseString(s1);
    cout << "After:  ";
    printCharVector(s1);
    cout << "String: \"" << vectorToString(s1) << "\"" << endl;
    cout << endl;

    // Test case 2: ["H","a","n","n","a","h"] -> Expected output: ["h","a","n","n","a","H"]
    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    cout << "Test 2 - Before: ";
    printCharVector(s2);
    cout << "String: \"" << vectorToString(s2) << "\"" << endl;
    solution.reverseString(s2);
    cout << "After:  ";
    printCharVector(s2);
    cout << "String: \"" << vectorToString(s2) << "\"" << endl;
    cout << endl;

    // Test case 3: ["A"] -> Expected output: ["A"]
    vector<char> s3 = {'A'};
    cout << "Test 3 - Before: ";
    printCharVector(s3);
    cout << "String: \"" << vectorToString(s3) << "\"" << endl;
    solution.reverseString(s3);
    cout << "After:  ";
    printCharVector(s3);
    cout << "String: \"" << vectorToString(s3) << "\"" << endl;
    cout << endl;

    // Test case 4: ["a","b"] -> Expected output: ["b","a"]
    vector<char> s4 = {'a', 'b'};
    cout << "Test 4 - Before: ";
    printCharVector(s4);
    cout << "String: \"" << vectorToString(s4) << "\"" << endl;
    solution.reverseString(s4);
    cout << "After:  ";
    printCharVector(s4);
    cout << "String: \"" << vectorToString(s4) << "\"" << endl;
    cout << endl;

    // Test case 5: Empty vector -> Expected output: []
    vector<char> s5 = {};
    cout << "Test 5 - Before: ";
    printCharVector(s5);
    cout << "String: \"" << vectorToString(s5) << "\"" << endl;
    solution.reverseString(s5);
    cout << "After:  ";
    printCharVector(s5);
    cout << "String: \"" << vectorToString(s5) << "\"" << endl;
    cout << endl;

    return 0;
}

/*
TWO-POINTER REVERSAL ALGORITHM EXPLANATION:
The algorithm uses two pointers moving towards each other from opposite ends.

How it works:
1. Initialize 'start' at index 0 and 'end' at index n-1
2. Swap characters at 'start' and 'end' positions
3. Move 'start' one step forward and 'end' one step backward
4. Repeat until pointers meet or cross each other

Example walkthrough with ['h','e','l','l','o']:
Initial: start=0, end=4, array=['h','e','l','l','o']

Step 1: Swap s[0] and s[4] -> ['o','e','l','l','h']
        start=1, end=3

Step 2: Swap s[1] and s[3] -> ['o','l','l','e','h']
        start=2, end=2

Step 3: start >= end, so we stop
Final result: ['o','l','l','e','h']

Edge cases handled:
- Empty array: while loop never executes
- Single character: start=0, end=0, condition start < end is false
- Even/odd length arrays: algorithm works for both

Time Complexity: O(n/2) = O(n) - we process each character once
Space Complexity: O(1) - in-place reversal using only two pointer variables

This is the most efficient approach for in-place string reversal!
*/