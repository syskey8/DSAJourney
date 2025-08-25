#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size(), idx = 0; // idx tracks the write position

        for (int i = 0; i < n; i++)
        {
            char ch = chars[i]; // Current character being processed
            int count = 0;      // Count of consecutive occurrences

            // Count consecutive occurrences of the same character
            while (i < n && chars[i] == ch)
            {
                count++;
                i++;
            }

            // Write the character
            chars[idx++] = ch;

            // If count > 1, write the count as well
            if (count > 1)
            {
                string str = to_string(count); // Convert count to string
                for (char dig : str)
                { // Write each digit
                    chars[idx++] = dig;
                }
            }

            i--; // Adjust for the for-loop increment (since we've already moved i)
        }

        chars.resize(idx);   // Trim the vector to compressed size
        return chars.size(); // Return the length of compressed array
    }

    // Alternative cleaner implementation without i-- adjustment
    int compressAlternative(vector<char> &chars)
    {
        int n = chars.size();
        int writeIdx = 0; // Position to write compressed data
        int readIdx = 0;  // Position to read original data

        while (readIdx < n)
        {
            char currentChar = chars[readIdx];
            int count = 0;

            // Count consecutive occurrences
            while (readIdx < n && chars[readIdx] == currentChar)
            {
                count++;
                readIdx++;
            }

            // Write character
            chars[writeIdx++] = currentChar;

            // Write count if greater than 1
            if (count > 1)
            {
                string countStr = to_string(count);
                for (char digit : countStr)
                {
                    chars[writeIdx++] = digit;
                }
            }
        }

        chars.resize(writeIdx);
        return chars.size();
    }
};

// Example usage:

void printCharVector(const vector<char> &chars)
{
    cout << "[";
    for (int i = 0; i < chars.size(); i++)
    {
        cout << "'" << chars[i] << "'";
        if (i < chars.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

string vectorToString(const vector<char> &chars)
{
    string result;
    for (char c : chars)
    {
        result += c;
    }
    return result;
}

int main()
{
    Solution solution;

    // Test case 1: ["a","a","b","b","c","c","c"] -> Expected: ["a","2","b","2","c","3"], length: 6
    vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout << "Test 1 - Before compression: ";
    printCharVector(chars1);
    cout << "String: \"" << vectorToString(chars1) << "\"" << endl;
    int len1 = solution.compress(chars1);
    cout << "After compression: ";
    printCharVector(chars1);
    cout << "String: \"" << vectorToString(chars1) << "\", Length: " << len1 << endl;
    cout << endl;

    // Test case 2: ["a"] -> Expected: ["a"], length: 1
    vector<char> chars2 = {'a'};
    cout << "Test 2 - Before compression: ";
    printCharVector(chars2);
    cout << "String: \"" << vectorToString(chars2) << "\"" << endl;
    int len2 = solution.compress(chars2);
    cout << "After compression: ";
    printCharVector(chars2);
    cout << "String: \"" << vectorToString(chars2) << "\", Length: " << len2 << endl;
    cout << endl;

    // Test case 3: ["a","b","b","b","b","b","b","b","b","b","b","b","b"] -> Expected: ["a","b","1","2"], length: 4
    vector<char> chars3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    cout << "Test 3 - Before compression: ";
    printCharVector(chars3);
    cout << "String: \"" << vectorToString(chars3) << "\"" << endl;
    int len3 = solution.compress(chars3);
    cout << "After compression: ";
    printCharVector(chars3);
    cout << "String: \"" << vectorToString(chars3) << "\", Length: " << len3 << endl;
    cout << endl;

    // Test case 4: ["a","a","a","b","b","a","a"] -> Expected: ["a","3","b","2","a","2"], length: 6
    vector<char> chars4 = {'a', 'a', 'a', 'b', 'b', 'a', 'a'};
    cout << "Test 4 - Before compression: ";
    printCharVector(chars4);
    cout << "String: \"" << vectorToString(chars4) << "\"" << endl;
    int len4 = solution.compress(chars4);
    cout << "After compression: ";
    printCharVector(chars4);
    cout << "String: \"" << vectorToString(chars4) << "\", Length: " << len4 << endl;
    cout << endl;

    // Test case 5: ["a","b","c"] -> Expected: ["a","b","c"], length: 3
    vector<char> chars5 = {'a', 'b', 'c'};
    cout << "Test 5 - Before compression: ";
    printCharVector(chars5);
    cout << "String: \"" << vectorToString(chars5) << "\"" << endl;
    int len5 = solution.compress(chars5);
    cout << "After compression: ";
    printCharVector(chars5);
    cout << "String: \"" << vectorToString(chars5) << "\", Length: " << len5 << endl;
    cout << endl;

    return 0;
}

/*
STRING COMPRESSION ALGORITHM EXPLANATION:

Your approach uses a two-pointer technique:
1. Read pointer (i): Scans through the original array
2. Write pointer (idx): Tracks where to write compressed data

Process:
1. For each character, count consecutive occurrences
2. Write the character to the write position
3. If count > 1, write the count digits after the character
4. Continue until all characters are processed
5. Resize array to compressed length

Example with ['a','a','b','b','c','c','c']:
- Start: i=0, idx=0
- Process 'a': count=2, write 'a' at idx=0, write '2' at idx=1, idx=2
- Process 'b': count=2, write 'b' at idx=2, write '2' at idx=3, idx=4
- Process 'c': count=3, write 'c' at idx=4, write '3' at idx=5, idx=6
- Result: ['a','2','b','2','c','3'], length=6

Key insights in your solution:
1. The `i--` adjustment is clever - it compensates for the for-loop increment
   since the while loop already advanced i past the current group
2. Using `to_string()` handles multi-digit counts correctly (e.g., count=12 -> "1", "2")
3. The condition `if(count == 1)` vs `else` is actually redundant - you can always
   write the character first, then conditionally write the count

Edge cases handled:
- Single characters (count=1): Only character is written, no count
- Multi-digit counts: Each digit written separately
- No consecutive characters: Each character written once

Time Complexity: O(n) - single pass through the array
Space Complexity: O(1) - in-place compression (excluding space for digit conversion)

Your solution is efficient and handles all edge cases correctly!
*/