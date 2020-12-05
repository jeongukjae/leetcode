// 20. Valid Parentheses
#include <stack>
#include <set>
#include <map>

using namespace std;

class Solution
{
private:
    set<char> openingBrackets = {'(', '{', '['};
    map<char, char> closingBracketsMap = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

public:
    bool isValid(string s)
    {
        stack<char> brackets;

        for (const auto ch : s)
        {
            if (openingBrackets.find(ch) != openingBrackets.end())
                brackets.push(ch);
            else
            {
                if (brackets.size() == 0)
                    return false;

                auto expected = closingBracketsMap[brackets.top()];
                if (ch != expected)
                    return false;

                brackets.pop();
            }
        }

        return brackets.size() == 0;
    }
};
