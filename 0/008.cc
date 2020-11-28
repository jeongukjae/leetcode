// 8. String to Integer (atoi)
//
// Implement atoi which converts a string to an integer.
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        auto iterator = s.begin();
        char ch;

        // remove whitespace
        while (true)
        {
            if (iterator == s.end())
                return 0;

            ch = *iterator;
            if (isdigit(ch) || ch == '-' || ch == '+')
                break;

            if (!isspace(ch))
                return 0;

            iterator++;
        }

        int result = 0;
        bool sign = true;
        if (ch == '-' || ch == '+')
        {
            sign = ch == '+';
            iterator++;
        }
        while (iterator != s.end())
        {
            ch = *iterator;
            if (!isdigit(ch))
                break;

            int num = ch - '0';

            if ((INT32_MAX / 10 < result) || (INT32_MAX / 10 == result && (sign ? INT32_MAX % 10 : -(INT32_MIN % 10)) <= num))
                return sign ? INT32_MAX : INT32_MIN;

            result *= 10;
            result += num;

            iterator++;
        }

        return result * (sign ? 1 : -1);
    }
};

int main()
{
    Solution s;

    assert(s.myAtoi("words and 987") == 0);
    assert(s.myAtoi("123") == 123);
    assert(s.myAtoi("-123") == -123);
    assert(s.myAtoi("  \t         -123") == -123);
    assert(s.myAtoi("--123") == 0);
    assert(s.myAtoi("+-123") == 0);
    assert(s.myAtoi("4193 with words") == 4193);
    assert(s.myAtoi("-2147483648") == -2147483648);
    assert(s.myAtoi("2147483646") == 2147483646);
    assert(s.myAtoi("-91283472332") == -2147483648);
    assert(s.myAtoi("-2147483647") == -2147483647);
}
