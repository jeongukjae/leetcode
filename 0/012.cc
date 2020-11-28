// 12. Integer to Roman

#include <string>
#include <iostream>
#include <cassert>

using namespace std;

// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
class Solution
{
public:
    string intToRoman(int num)
    {
        string result;
        int tmp;

        if ((tmp = num / 1000) != 0)
        {
            result += string(tmp, 'M');
            num %= 1000;
        }

        if ((tmp = num / 100) != 0)
        {
            if (tmp == 9)
                result += "CM";
            else if (tmp >= 5)
                result += 'D' + string(tmp - 5, 'C');
            else if (tmp == 4)
                result += "CD";
            else
                result += string(tmp, 'C');
            num %= 100;
        }

        if ((tmp = num / 10) != 0)
        {
            if (tmp == 9)
                result += "XC";
            else if (tmp >= 5)
                result += 'L' + string(tmp - 5, 'X');
            else if (tmp == 4)
                result += "XL";
            else
                result += string(tmp, 'X');
            num %= 10;
        }

        if (num == 9)
            result += "IX";
        else if (num >= 5)
            result += 'V' + string(num - 5, 'I');
        else if (num == 4)
            result += "IV";
        else
            result += string(num, 'I');

        return result;
    }
};

int main()
{
    Solution s;
    assert(s.intToRoman(4) == "IV");
    assert(s.intToRoman(9) == "IX");
    assert(s.intToRoman(58) == "LVIII");
    assert(s.intToRoman(1994) == "MCMXCIV");
}
