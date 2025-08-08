#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(const string &s)
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

string findLongestPalindrome(const vector<string> &strings)
{
    string longestPalindrome = "";

    for (const string &s : strings)
    {
        if (isPalindrome(s))
        {
            if (s.length() > longestPalindrome.length())
            {
                longestPalindrome = s;
            }
        }
    }
    return longestPalindrome;
}

int main()
{
    vector<string> myStrings = {"karan", "racecar", "madam", "azRao", "sahil"};
    string result = findLongestPalindrome(myStrings);

    if (!result.empty())
    {
        cout << "The longest palindrome is: " << result << endl;
    }
    else
    {
        cout << "No palindrome found." << endl;
    }

    return 0;
}