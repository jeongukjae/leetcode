// 13. Roman to Integer

#include <string>
#include <iostream>
#include <cassert>
#include <map>

using namespace std;

class Solution
{
private:
    int getInt(char ch)
    {
        switch (ch)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        return 0;
    }

public:
    int romanToInt(string s)
    {
        int result = 0;
        int previousValue = 0;

        for (int i = 0, length = s.length(); i < length; i++)
        {
            char ch = s[i];
            int value = getInt(ch);

            if (previousValue < value)
                result -= previousValue + previousValue;
            result += value;
            previousValue = value;
        }

        return result;
    }
};

int main()
{
    Solution s;
    assert(s.romanToInt("III") == 3);
    assert(s.romanToInt("IV") == 4);
    assert(s.romanToInt("IX") == 9);
    assert(s.romanToInt("LVIII") == 58);
    assert(s.romanToInt("MCMXCIV") == 1994);
}
