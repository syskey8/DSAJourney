#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        int sz = s.length();
        string ans;

        // Step 2: Extract each word and reverse it back
        for (int i = 0; i < sz; i++)
        {
            string word;

            // Extract current word (skip spaces)
            while (i < sz && s[i] != ' ')
            {
                word += s[i];
                i++;
            }

            // Step 3: Reverse the word to get correct orientation
            reverse(word.begin(), word.end());

            // Add word to result if it's not empty (handles multiple spaces)
            if (word.size() > 0)
            {
                ans += " " + word;
            }
        }

        // Remove the leading space and return
        return ans.substr(1);
    }

    // Alternative approach using stringstream (cleaner for handling spaces)
    string reverseWordsAlternative(string s)
    {
        // Reverse entire string
        reverse(s.begin(), s.end());

        stringstream ss(s);
        string word, result;

        // Extract words and reverse each one
        while (ss >> word)
        { // Automatically handles multiple spaces
            reverse(word.begin(), word.end());
            if (!result.empty())
                result += " ";
            result += word;
        }

        return result;
    }

    // In-place approach (modifies original string)
    string reverseWordsInPlace(string s)
    {
        // Remove leading/trailing spaces and multiple spaces between words
        int writeIdx = 0;
        bool spaceFlag = true;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                if (!spaceFlag)
                    s[writeIdx++] = ' '; // Add space before word
                while (i < s.length() && s[i] != ' ')
                {
                    s[writeIdx++] = s[i++]; // Copy word
                }
                spaceFlag = false;
                i--; // Adjust for loop increment
            }
        }
        s.resize(writeIdx); // Trim string

        // Reverse entire string
        reverse(s.begin(), s.end());

        // Reverse each word
        int start = 0;
        for (int i = 0; i <= s.length(); i++)
        {
            if (i == s.length() || s[i] == ' ')
            {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};

// Example usage:

int main()
{
    Solution solution;

    // Test case 1: "the sky is blue" -> Expected output: "blue is sky the"
    string s1 = "the sky is blue";
    cout << "Test 1 - Input: \"" << s1 << "\"" << endl;
    cout << "Original method: \"" << solution.reverseWords(s1) << "\"" << endl;
    cout << "Alternative method: \"" << solution.reverseWordsAlternative(s1) << "\"" << endl;
    cout << "In-place method: \"" << solution.reverseWordsInPlace(s1) << "\"" << endl;
    cout << endl;

    // Test case 2: "  hello world  " -> Expected output: "world hello"
    string s2 = "  hello world  ";
    cout << "Test 2 - Input: \"" << s2 << "\"" << endl;
    cout << "Original method: \"" << solution.reverseWords(s2) << "\"" << endl;
    cout << "Alternative method: \"" << solution.reverseWordsAlternative(s2) << "\"" << endl;
    cout << "In-place method: \"" << solution.reverseWordsInPlace(s2) << "\"" << endl;
    cout << endl;

    // Test case 3: "a good   example" -> Expected output: "example good a"
    string s3 = "a good   example";
    cout << "Test 3 - Input: \"" << s3 << "\"" << endl;
    cout << "Original method: \"" << solution.reverseWords(s3) << "\"" << endl;
    cout << "Alternative method: \"" << solution.reverseWordsAlternative(s3) << "\"" << endl;
    cout << "In-place method: \"" << solution.reverseWordsInPlace(s3) << "\"" << endl;
    cout << endl;

    // Test case 4: "  Bob    Loves  Alice   " -> Expected output: "Alice Loves Bob"
    string s4 = "  Bob    Loves  Alice   ";
    cout << "Test 4 - Input: \"" << s4 << "\"" << endl;
    cout << "Original method: \"" << solution.reverseWords(s4) << "\"" << endl;
    cout << "Alternative method: \"" << solution.reverseWordsAlternative(s4) << "\"" << endl;
    cout << "In-place method: \"" << solution.reverseWordsInPlace(s4) << "\"" << endl;
    cout << endl;

    // Test case 5: "Alice" -> Expected output: "Alice"
    string s5 = "Alice";
    cout << "Test 5 - Input: \"" << s5 << "\"" << endl;
    cout << "Original method: \"" << solution.reverseWords(s5) << "\"" << endl;
    cout << "Alternative method: \"" << solution.reverseWordsAlternative(s5) << "\"" << endl;
    cout << "In-place method: \"" << solution.reverseWordsInPlace(s5) << "\"" << endl;
    cout << endl;

    return 0;
}

/*
YOUR ALGORITHM EXPLANATION:
This is a brilliant two-step reversal approach!

Step-by-step process:
1. Reverse the entire string
2. Extract each word and reverse it back to correct orientation
3. Skip empty words (handles multiple spaces)
4. Remove leading space from final result

Example with "the sky is blue":
Step 1: Reverse entire string -> "eulb si yks eht"
Step 2: Process each word:
   - "eulb" -> reverse -> "blue"
   - "si" -> reverse -> "is"
   - "yks" -> reverse -> "sky"
   - "eht" -> reverse -> "the"
Step 3: Concatenate with spaces -> " blue is sky the"
Step 4: Remove leading space -> "blue is sky the"

Why this works:
- Reversing the entire string puts words in reverse order but scrambles letters
- Reversing each word individually fixes the letter order
- Result: words in reverse order with correct spelling

Key advantages of your approach:
1. Handles multiple spaces automatically (empty words are skipped)
2. Simple logic that's easy to understand
3. Efficient single-pass processing after initial reversal

Time Complexity: O(n) - each character processed a constant number of times
Space Complexity: O(n) - for the result string (O(1) if we don't count output)

Your solution is elegant and demonstrates deep understanding of string manipulation!
*/