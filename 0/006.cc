// 6. ZigZag Conversion
//
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        auto length = s.length();
        string result = "";
        result.reserve(length);

        int numCharInSinglePattern = numRows * 2 - 2;
        for (int row = 0; row < numRows; row++)
        {
            for (int col = row; col < length;)
            {
                result.push_back(s[col]);
                auto temp = col + (numRows - row - 1) * 2;
                if (row != 0 && row != numRows - 1 && temp < length)
                    result.push_back(s[temp]);

                col += numCharInSinglePattern;
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    std::cout << s.convert("PAYPALISHIRING", 3) << std::endl;
    std::cout << "PAHNAPLSIIGYIR" << std::endl;
    std::cout << s.convert("PAYPALISHIRING", 4) << std::endl;
    std::cout << "PINALSIGYAHRPI" << std::endl;
    std::cout << s.convert("A", 1) << std::endl;
    std::cout << "A" << std::endl;
    std::cout << s.convert("A", 4) << std::endl;
    std::cout << "A" << std::endl;
}
