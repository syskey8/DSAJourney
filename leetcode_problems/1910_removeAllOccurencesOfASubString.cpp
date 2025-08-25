#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        // Keep removing occurrences until none are found
        while (s.length() > 0 && s.find(part) < s.length())
        {
            // Find the first occurrence of 'part' and remove it
            s.erase(s.find(part), part.length());
        }

        return s;
    }

    // Alternative implementation using string::npos for clearer intent
    string removeOccurrencesAlternative(string s, string part)
    {
        size_t pos;
        // Keep finding and removing occurrences
        while ((pos = s.find(part)) != string::npos)
        {
            s.erase(pos, part.length());
        }
        return s;
    }

    // Stack-based approach (more efficient for overlapping patterns)
    string removeOccurrencesStack(string s, string part)
    {
        string result = "";

        for (char c : s)
        {
            result += c; // Add current character

            // Check if the end of result matches the pattern
            if (result.length() >= part.length())
            {
                if (result.substr(result.length() - part.length()) == part)
                {
                    // Remove the pattern from the end
                    result.erase(result.length() - part.length());
                }
            }
        }

        return result;
    }
};

// Example usage:

int main()
{
    Solution solution;

    // Test case 1: s="daabcbaabcbc", part="abc" -> Expected output: "dab"
    string s1 = "daabcbaabcbc";
    string part1 = "abc";
    cout << "Test 1 - Input: \"" << s1 << "\", part: \"" << part1 << "\"" << endl;
    cout << "Original method: \"" << solution.removeOccurrences(s1, part1) << "\"" << endl;
    cout << "Alternative method: \"" << solution.removeOccurrencesAlternative(s1, part1) << "\"" << endl;
    cout << "Stack method: \"" << solution.removeOccurrencesStack(s1, part1) << "\"" << endl;
    cout << endl;

    // Test case 2: s="abcabc", part="abc" -> Expected output: ""
    string s2 = "abcabc";
    string part2 = "abc";
    cout << "Test 2 - Input: \"" << s2 << "\", part: \"" << part2 << "\"" << endl;
    cout << "Original method: \"" << solution.removeOccurrences(s2, part2) << "\"" << endl;
    cout << "Alternative method: \"" << solution.removeOccurrencesAlternative(s2, part2) << "\"" << endl;
    cout << "Stack method: \"" << solution.removeOccurrencesStack(s2, part2) << "\"" << endl;
    cout << endl;

    // Test case 3: s="axxxxyyyyb", part="xy" -> Expected output: "ab"
    string s3 = "axxxxyyyyb";
    string part3 = "xy";
    cout << "Test 3 - Input: \"" << s3 << "\", part: \"" << part3 << "\"" << endl;
    cout << "Original method: \"" << solution.removeOccurrences(s3, part3) << "\"" << endl;
    cout << "Alternative method: \"" << solution.removeOccurrencesAlternative(s3, part3) << "\"" << endl;
    cout << "Stack method: \"" << solution.removeOccurrencesStack(s3, part3) << "\"" << endl;
    cout << endl;

    // Test case 4: s="hello", part="world" -> Expected output: "hello"
    string s4 = "hello";
    string part4 = "world";
    cout << "Test 4 - Input: \"" << s4 << "\", part: \"" << part4 << "\"" << endl;
    cout << "Original method: \"" << solution.removeOccurrences(s4, part4) << "\"" << endl;
    cout << "Alternative method: \"" << solution.removeOccurrencesAlternative(s4, part4) << "\"" << endl;
    cout << "Stack method: \"" << solution.removeOccurrencesStack(s4, part4) << "\"" << endl;
    cout << endl;

    // Test case 5: s="ababa", part="aba" -> Expected output: "a"
    string s5 = "ababa";
    string part5 = "aba";
    cout << "Test 5 - Input: \"" << s5 << "\", part: \"" << part5 << "\"" << endl;
    cout << "Original method: \"" << solution.removeOccurrences(s5, part5) << "\"" << endl;
    cout << "Alternative method: \"" << solution.removeOccurrencesAlternative(s5, part5) << "\"" << endl;
    cout << "Stack method: \"" << solution.removeOccurrencesStack(s5, part5) << "\"" << endl;
    cout << endl;

    return 0;
}

/*
ALGORITHM EXPLANATION:

Your Original Approach:
- Repeatedly find the first occurrence of 'part' in string 's'
- Remove it using erase() function
- Continue until no more occurrences exist
- Uses s.find(part) < s.length() to check if pattern exists

How s.find() works:
- Returns the position of first occurrence if found
- Returns string::npos (usually a very large number) if not found
- Your condition s.find(part) < s.length() is equivalent to checking != string::npos

Example walkthrough with s="daabcbaabcbc", part="abc":
Step 1: s="daabcbaabcbc", find "abc" at position 2, remove it -> s="dbaabcbc"
Step 2: s="dbaabcbc", find "abc" at position 3, remove it -> s="dbbc"
Step 3: s="dbbc", "abc" not found, exit loop
Final result: "dbbc"

Wait, let me recalculate:
Step 1: s="daabcbaabcbc", find "abc" at pos 2 -> s="dbaabcbc"
Step 2: s="dbaabcbc", find "abc" at pos 2 -> s="dbbc"
Step 3: s="dbbc", no "abc" found, done
Hmm, expected "dab" but got "dbbc"...

Actually, let me trace this correctly:
Original: "daabcbaabcbc"
Step 1: Remove first "abc" at pos 2: "da" + "baabcbc" = "dabaabcbc"
Step 2: Remove "abc" at pos 4: "daba" + "bc" = "dababc"
Wait, this doesn't seem right...

Let me try the correct trace:
"daabcbaabcbc" -> remove "abc" at pos 2 -> "da" + "baabcbc" = "dabaabcbc"
"dabaabcbc" -> remove "abc" at pos 4 -> "daba" + "bc" = "dababc"
This still has "abc", so:
"dababc" -> remove "abc" at pos 3 -> "dab"

Time Complexity: O(n*m*k) where n=string length, m=pattern length, k=number of occurrences
Space Complexity: O(1) - modifies string in place

The algorithm works correctly but can be inefficient for many overlapping patterns.
The stack-based approach is more efficient for such cases.
*/