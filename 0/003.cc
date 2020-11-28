// 3. Longest Substring Without Repeating Characters
//
// Given a string s, find the length of the longest substring without repeating characters.

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        const char *data = s.data();
        int length = s.length();

        int longest = 0;
        map<char, int> occured; // character -> last index
        int lastRepeated = 0;

        for (int index = 0; index < length; index++)
        {
            if (occured.find(data[index]) != occured.end())
            {
                longest = max(longest, min(index - lastRepeated, getMaxLength(index, occured)));
                lastRepeated = max(lastRepeated, occured[data[index]] + 1);
            }
            occured[data[index]] = index;
        }

        if (occured.size() > 0)
            longest = max(longest, min(length - lastRepeated, getMaxLength(length, occured)));

        return longest;
    }

    static int getMaxLength(int index, map<char, int> &occured)
    {
        int result = 0;

        for (auto element : occured)
            result = max(index - element.second, result);

        return result;
    }
};

int main()
{
    Solution s;

    std::cout << s.lengthOfLongestSubstring("abcabcbb") << ", 3" << std::endl;
    std::cout << s.lengthOfLongestSubstring("bbbbb") << ", 1" << std::endl;
    std::cout << s.lengthOfLongestSubstring("pwwkew") << ", 3" << std::endl;
    std::cout << s.lengthOfLongestSubstring("") << ", 0" << std::endl;
    std::cout << s.lengthOfLongestSubstring(" ") << ", 1" << std::endl;
    std::cout << s.lengthOfLongestSubstring("au") << ", 2" << std::endl;
    std::cout << s.lengthOfLongestSubstring("cdd") << ", 2" << std::endl;
    std::cout << s.lengthOfLongestSubstring("abba") << ", 2" << std::endl;
    std::cout << s.lengthOfLongestSubstring("dvdf") << ", 3" << std::endl;
    std::cout << s.lengthOfLongestSubstring("uqinntq") << ", 4" << std::endl;
}
