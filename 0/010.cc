// 10. Regular Expression Matching
//
// Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where:
// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        // parse patterns
        vector<pair<char, bool>> patterns;
        patterns.reserve(20);
        for (int i = 0, length = p.length(); i < length; i++)
        {
            if (i + 1 < length && p[i + 1] == '*')
            {
                patterns.push_back(make_pair(p[i], true));
                i++;
            }
            else
            {
                patterns.push_back(make_pair(p[i], false));
            }
        }

        // create cache
        int **cache = new int *[s.length() + 1];
        for (int i = 0; i < s.length() + 1; i++)
        {
            cache[i] = new int[patterns.size() + 1];
            for (int j = 0; j < patterns.size() + 1; j++)
                cache[i][j] = 2;
        }

        // find
        auto result = match(s, patterns, 0, 0, cache) == 1;

        // cleanup
        for (int i = 0; i < s.length() + 1; i++)
            delete[] cache[i];
        delete[] cache;
        return result;
    }

    bool match(string &s, vector<pair<char, bool>> &p, int stringIndex, int patternIndex, int **cache)
    {
        if (cache[stringIndex][patternIndex] == 2)
        {
            if (patternIndex == p.size())
                cache[stringIndex][patternIndex] = s.length() == stringIndex;
            else
            {
                bool matched = stringIndex < s.length() && (s[stringIndex] == p[patternIndex].first || p[patternIndex].first == '.');
                if (p[patternIndex].second)
                    cache[stringIndex][patternIndex] = match(s, p, stringIndex, patternIndex + 1, cache) || (matched && match(s, p, stringIndex + 1, patternIndex, cache));
                else
                    cache[stringIndex][patternIndex] = matched && match(s, p, stringIndex + 1, patternIndex + 1, cache);
            }
        }

        return cache[stringIndex][patternIndex];
    }
};

int main()
{
    Solution s;

    assert(s.isMatch("aa", "a") == false);
    assert(s.isMatch("aa", "a*") == true);
    assert(s.isMatch("ab", ".*") == true);
    assert(s.isMatch("aab", "c*a*b") == true);
    assert(s.isMatch("mississippi", "mis*is*p*.") == false);
    assert(s.isMatch("ab", ".*c") == false);
    assert(s.isMatch("aaa", "aaaa") == false);
    assert(s.isMatch("aaa", "a*a") == true);
}
