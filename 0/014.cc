// 14. Longest Common Prefix

#include <string>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int length = strs.size();
        int maxLength = 0;

        if (length == 0)
            return "";

        for (int i = 0; i < length; i++)
            maxLength = max((int)strs[i].length(), maxLength);

        int i;
        for (i = 0; i < maxLength; i++)
        {
            char crit = strs[0][i];
            for (int j = 1; j < length; j++)
                if (crit != strs[j][i])
                    goto breakAll;
        }
    breakAll:

        return strs[0].substr(0, i);
    }
};

int main()
{
    Solution s;
    {
        vector<string> strs{"flower", "flow", "flight"};
        assert(s.longestCommonPrefix(strs) == "fl");
    }
    {
        vector<string> strs{"dog", "racecar", "car"};
        assert(s.longestCommonPrefix(strs) == "");
    }
}
