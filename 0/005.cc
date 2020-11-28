// 5. Longest Palindromic Substring
//
// Given a string s, return the longest palindromic substring in s.
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    // method 1
    string longestPalindrome(string s)
    {
        int maxLength = 0;
        int maxLengthPosition = 0;
        int length = s.length();

        for (int i = 0; i < length; i++)
        {
            // odd
            int j;
            auto lengthToSearch = min(i, length - i - 1);
            for (j = 1; j <= lengthToSearch && s[i - j] == s[i + j]; j++)
                ;
            j--;

            if (2 * j + 1 > maxLength)
            {
                maxLengthPosition = i - j;
                maxLength = 2 * j + 1;
            }

            // even
            lengthToSearch = min(i + 1, length - i - 1);
            for (j = 1; j <= lengthToSearch && s[i - j + 1] == s[i + j]; j++)
                ;
            j--;

            if (2 * j > maxLength)
            {
                maxLengthPosition = i - j + 1;
                maxLength = 2 * j;
            }
        }

        return s.substr(maxLengthPosition, maxLength);
    }
};

int main()
{
    Solution s;
    std::cout << s.longestPalindrome("babad") << ", bab" << std::endl;
    std::cout << s.longestPalindrome("cbbd") << ", bb" << std::endl;
    std::cout << s.longestPalindrome("a") << ", a" << std::endl;
    std::cout << s.longestPalindrome("ac") << ", a" << std::endl;
    std::cout << s.longestPalindrome("bb") << ", bb" << std::endl;
}
