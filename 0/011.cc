// 11. Container With Most Water
//
// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        auto data = height.data();
        auto length = height.size();
        int maxSize = 0;

        int left = 0, right = length - 1;
        int leftValue = data[left], rightValue = data[right];

        while (true)
        {
            maxSize = max(maxSize, (right - left) * min(rightValue, leftValue));

            if (leftValue < rightValue)
            {
                left++;
                leftValue = data[left];
            }
            else
            {
                right--;
                leftValue = data[right];
            }

            if (left == right)
                break;
        }

        return maxSize;
    }
};

int main()
{
    Solution s;

    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(s.maxArea(height) == 49);

    height = {1, 1};
    assert(s.maxArea(height) == 1);

    height = {4, 3, 2, 1, 4};
    assert(s.maxArea(height) == 16);

    height = {1, 2, 1};
    assert(s.maxArea(height) == 2);
}
