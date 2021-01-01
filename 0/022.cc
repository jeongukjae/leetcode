// 22. Generate Parentheses
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;

        searchParenthesisCombinations(n, result, "", 0, 0);

        return result;
    }

private:
    void searchParenthesisCombinations(int n, vector<string> &result, string current, int numOpenedParenthesis, int numClosedParenthesis)
    {
        if (numClosedParenthesis == n)
        {
            result.push_back(current);
            return;
        }

        if (numOpenedParenthesis > 0)
            searchParenthesisCombinations(n, result, current + ")", numOpenedParenthesis - 1, numClosedParenthesis + 1);
        if (numOpenedParenthesis + numClosedParenthesis < n)
            searchParenthesisCombinations(n, result, current + "(", numOpenedParenthesis + 1, numClosedParenthesis);
    }
};
