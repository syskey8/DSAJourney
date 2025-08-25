#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    // Helper function to check if a character is alphanumeric
    bool isAlphanum(char ch)
    { // Fixed typo: "isAplhanum" -> "isAlphanum"
        if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
            return true;
        return false;
    }

    bool isPalindrome(string s)
    {
        int st = 0, end = s.length() - 1; // Two pointers at start and end

        while (st < end)
        {
            // Skip non-alphanumeric characters from the left
            if (!isAlphanum(s[st]))
            {
                st++;
                continue;
            }

            // Skip non-alphanumeric characters from the right
            if (!isAlphanum(s[end]))
            {
                end--;
                continue;
            }

            // Compare characters (case-insensitive)
            if (tolower(s[st]) != tolower(s[end]))
            {
                return false; // Not a palindrome
            }

            // Move both pointers towards center
            st++;
            end--;
        }

        return true; // It's a palindrome
    }
};

// Example usage:

int main()
{
    Solution solution;

    // Test case 1: "A man, a plan, a canal: Panama" -> Expected output: true
    string s1 = "A man, a plan, a canal: Panama";
    cout << "Test 1 - Input: \"" << s1 << "\"" << endl;
    cout << "Is palindrome: " << (solution.isPalindrome(s1) ? "true" : "false") << endl;
    cout << endl;

    // Test case 2: "race a car" -> Expected output: false
    string s2 = "race a car";
    cout << "Test 2 - Input: \"" << s2 << "\"" << endl;
    cout << "Is palindrome: " << (solution.isPalindrome(s2) ? "true" : "false") << endl;
    cout << endl;

    // Test case 3: " " -> Expected output: true (empty after removing non-alphanumeric)
    string s3 = " ";
    cout << "Test 3 - Input: \"" << s3 << "\"" << endl;
    cout << "Is palindrome: " << (solution.isPalindrome(s3) ? "true" : "false") << endl;
    cout << endl;

    // Test case 4: "Madam" -> Expected output: true
    string s4 = "Madam";
    cout << "Test 4 - Input: \"" << s4 << "\"" << endl;
    cout << "Is palindrome: " << (solution.isPalindrome(s4) ? "true" : "false") << endl;
    cout << endl;

    // Test case 5: "No 'x' in Nixon" -> Expected output: true
    string s5 = "No 'x' in Nixon";
    cout << "Test 5 - Input: \"" << s5 << "\"" << endl;
    cout << "Is palindrome: " << (solution.isPalindrome(s5) ? "true" : "false") << endl;
    cout << endl;

    // Test case 6: "12321" -> Expected output: true
    string s6 = "12321";
    cout << "Test 6 - Input: \"" << s6 << "\"" << endl;
    cout << "Is palindrome: " << (solution.isPalindrome(s6) ? "true" : "false") << endl;
    cout << endl;

    // Test case 7: "A Santa at NASA" -> Expected output: true
    string s7 = "A Santa at NASA";
    cout << "Test 7 - Input: \"" << s7 << "\"" << endl;
    cout << "Is palindrome: " << (solution.isPalindrome(s7) ? "true" : "false") << endl;
    cout << endl;

    return 0;
}

/*
VALID PALINDROME ALGORITHM EXPLANATION:
The problem requires checking if a string is a palindrome considering only alphanumeric
characters and ignoring case.

Approach:
1. Use two pointers starting from both ends
2. Skip non-alphanumeric characters from both sides
3. Compare characters in lowercase
4. If any pair doesn't match, it's not a palindrome
5. If we successfully compare all characters, it's a palindrome

Example walkthrough with "A man, a plan, a canal: Panama":
- Remove non-alphanumeric and convert to lowercase: "amanaplanacanalpanama"
- Use two pointers to compare:
  - 'a' == 'a' ✓
  - 'm' == 'm' ✓
  - 'a' == 'a' ✓
  - 'n' == 'n' ✓
  - ... and so on
- All characters match, so it's a palindrome

Key optimizations in your solution:
1. No extra space needed - processes string in-place
2. Skips non-alphanumeric characters on-the-fly
3. Case-insensitive comparison using tolower()
4. Early termination if mismatch found

Time Complexity: O(n) - single pass through the string
Space Complexity: O(1) - only using two pointer variables

Your helper function isAlphanum() correctly identifies:
- Digits: '0' to '9'
- Letters: 'a' to 'z' and 'A' to 'Z' (using tolower for case handling)
*/