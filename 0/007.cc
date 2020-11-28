// 7. Reverse Integer
//
// Given a 32-bit signed integer, reverse digits of an integer.

#include <cassert>
#include <limits>
#include <iostream>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long result = 0;
        while (x != 0)
        {
            result *= 10;
            result += x % 10;

            if (result > INT32_MAX || result < INT32_MIN)
                return 0;
            x /= 10;
        }
        return result;
    }
};

int main()
{
    Solution s;

    assert(s.reverse(-321) == -123);
    assert(s.reverse(0) == 0);
    assert(s.reverse(120) == 21);
    assert(s.reverse(-123) == -321);
    assert(s.reverse(123) == 321);
    assert(s.reverse(1000000009) == 0);
    assert(s.reverse(-2147483648) == 0);
}
