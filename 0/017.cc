// 17. Letter Combinations of a Phone Number
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <cassert>
#include <map>

using namespace std;

class Solution
{
private:
    map<char, string> intMaps = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return {};

        vector<string> result;
        int totalCases = 1;
        for (char digit : digits)
            totalCases *= intMaps[digit].length();
        result.reserve(totalCases);

        findCase("", digits, result);

        return result;
    }

    void findCase(string current, string_view digits, vector<string> &cases)
    {
        if (digits.length() == 0)
        {
            cases.push_back(current);
            return;
        }

        for (auto ch : intMaps[digits[0]])
            findCase(current + ch, digits.substr(1, std::string_view::npos), cases);
    }
};

int main()
{
    Solution s;

    {
        auto result = s.letterCombinations("23");
        for (auto item : result)
            std::cout << item << " ";
        std::cout << std::endl;
    }
}
