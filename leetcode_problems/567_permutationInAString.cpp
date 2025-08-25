#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    // Helper function to compare two frequency arrays
    bool isFreqSame(int freq1[], int freq2[])
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] != freq2[i])
            {
                return false;
            }
        }
        return true;
    }

    // Your original solution (works correctly)
    bool checkInclusion(string s1, string s2)
    {
        // Create frequency array for s1
        int freq[26] = {0};
        for (int i = 0; i < s1.length(); i++)
        {
            freq[s1[i] - 'a']++; // Map 'a'->0, 'b'->1, etc.
        }

        int windSize = s1.length();

        // Check every possible window of size windSize in s2
        for (int i = 0; i < s2.length(); i++)
        {
            int windIdx = 0, idx = i;
            int windFreq[26] = {0};

            // Build frequency array for current window
            while (windIdx < windSize && idx < s2.length())
            {
                windFreq[s2[idx] - 'a']++;
                windIdx++;
                idx++;
            }

            // Check if current window has same frequency as s1
            if (isFreqSame(freq, windFreq))
            {
                return true; // Found a permutation
            }
        }

        return false; // No permutation found
    }

    // Optimized sliding window solution
    bool checkInclusionOptimized(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;

        int freq1[26] = {0}; // Frequency of s1
        int freq2[26] = {0}; // Frequency of current window

        // Initialize frequency arrays for first window
        for (int i = 0; i < s1.length(); i++)
        {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        // Check if first window matches
        if (isFreqSame(freq1, freq2))
            return true;

        // Slide the window
        for (int i = s1.length(); i < s2.length(); i++)
        {
            // Remove the leftmost character of previous window
            freq2[s2[i - s1.length()] - 'a']--;
            // Add the new character to current window
            freq2[s2[i] - 'a']++;

            // Check if current window matches
            if (isFreqSame(freq1, freq2))
                return true;
        }

        return false;
    }

    // Most optimized version using matches counter
    bool checkInclusionMostOptimized(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;

        int freq1[26] = {0};
        int freq2[26] = {0};

        // Build frequency for s1 and first window of s2
        for (int i = 0; i < s1.length(); i++)
        {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        // Count how many characters have matching frequencies
        int matches = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] == freq2[i])
                matches++;
        }

        // If all 26 characters match, we found a permutation
        if (matches == 26)
            return true;

        // Slide the window
        for (int i = s1.length(); i < s2.length(); i++)
        {
            int left = s2[i - s1.length()] - 'a'; // Character leaving window
            int right = s2[i] - 'a';              // Character entering window

            // Update matches for character leaving the window
            if (freq1[left] == freq2[left])
                matches--;
            freq2[left]--;
            if (freq1[left] == freq2[left])
                matches++;

            // Update matches for character entering the window
            if (freq1[right] == freq2[right])
                matches--;
            freq2[right]++;
            if (freq1[right] == freq2[right])
                matches++;

            // Check if we have a match
            if (matches == 26)
                return true;
        }

        return false;
    }
};

// Example usage:

int main()
{
    Solution solution;

    // Test case 1: s1="ab", s2="eidbaooo" -> Expected output: true
    string s1_1 = "ab", s2_1 = "eidbaooo";
    cout << "Test 1 - s1: \"" << s1_1 << "\", s2: \"" << s2_1 << "\"" << endl;
    cout << "Original: " << (solution.checkInclusion(s1_1, s2_1) ? "true" : "false") << endl;
    cout << "Optimized: " << (solution.checkInclusionOptimized(s1_1, s2_1) ? "true" : "false") << endl;
    cout << "Most Optimized: " << (solution.checkInclusionMostOptimized(s1_1, s2_1) ? "true" : "false") << endl;
    cout << endl;

    // Test case 2: s1="ab", s2="eidboaoo" -> Expected output: false
    string s1_2 = "ab", s2_2 = "eidboaoo";
    cout << "Test 2 - s1: \"" << s1_2 << "\", s2: \"" << s2_2 << "\"" << endl;
    cout << "Original: " << (solution.checkInclusion(s1_2, s2_2) ? "true" : "false") << endl;
    cout << "Optimized: " << (solution.checkInclusionOptimized(s1_2, s2_2) ? "true" : "false") << endl;
    cout << "Most Optimized: " << (solution.checkInclusionMostOptimized(s1_2, s2_2) ? "true" : "false") << endl;
    cout << endl;

    // Test case 3: s1="adc", s2="dcda" -> Expected output: true
    string s1_3 = "adc", s2_3 = "dcda";
    cout << "Test 3 - s1: \"" << s1_3 << "\", s2: \"" << s2_3 << "\"" << endl;
    cout << "Original: " << (solution.checkInclusion(s1_3, s2_3) ? "true" : "false") << endl;
    cout << "Optimized: " << (solution.checkInclusionOptimized(s1_3, s2_3) ? "true" : "false") << endl;
    cout << "Most Optimized: " << (solution.checkInclusionMostOptimized(s1_3, s2_3) ? "true" : "false") << endl;
    cout << endl;

    // Test case 4: s1="hello", s2="ooolleoooleh" -> Expected output: false
    string s1_4 = "hello", s2_4 = "ooolleoooleh";
    cout << "Test 4 - s1: \"" << s1_4 << "\", s2: \"" << s2_4 << "\"" << endl;
    cout << "Original: " << (solution.checkInclusion(s1_4, s2_4) ? "true" : "false") << endl;
    cout << "Optimized: " << (solution.checkInclusionOptimized(s1_4, s2_4) ? "true" : "false") << endl;
    cout << "Most Optimized: " << (solution.checkInclusionMostOptimized(s1_4, s2_4) ? "true" : "false") << endl;
    cout << endl;

    return 0;
}

/*
ALGORITHM COMPARISON:

Your Original Solution:
- Time Complexity: O(n*m*26) where n=s2.length(), m=s1.length()
- Space Complexity: O(1) - fixed size arrays
- Approach: For each position, rebuild frequency array and compare

Optimized Sliding Window:
- Time Complexity: O(n*26) - slide window once, compare frequencies each time
- Space Complexity: O(1) - fixed size arrays
- Approach: Maintain window frequency, slide by adding/removing one character

Most Optimized (Matches Counter):
- Time Complexity: O(n) - only update matches counter, no array comparison
- Space Complexity: O(1) - fixed size arrays
- Approach: Track how many characters have matching frequencies

Example with s1="ab", s2="eidbaooo":
- s1 frequency: a=1, b=1, others=0
- Check windows: "ei"❌, "id"❌, "db"❌, "ba"✓ (b=1, a=1 matches!)

Your original solution is correct and educational, showing clear logic.
The optimizations improve performance but use the same core sliding window concept.
*/