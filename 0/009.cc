// 9. Palindrome Number
//
// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;

        int reverted = 0;
        int tmp = x;
        int threshold = INT32_MAX / 10;
        while (tmp != 0)
        {
            if (threshold < reverted)
                return false;

            reverted *= 10;
            reverted += tmp % 10;
            tmp /= 10;
        }

        return x == reverted;
    }
};

int main()
{
    Solution s;

    assert(s.isPalindrome(-121) == false);
    assert(s.isPalindrome(-101) == false);
    assert(s.isPalindrome(10) == false);
    assert(s.isPalindrome(121) == true);
    assert(s.isPalindrome(123) == false);
    assert(s.isPalindrome(765467) == false);
    assert(s.isPalindrome(765567) == true);
    assert(s.isPalindrome(7653567) == true);
    assert(s.isPalindrome(1234567899) == false);
}
