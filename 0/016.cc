// 16. 3Sum Closest

#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int closest = 100000;
        std::sort(nums.begin(), nums.end());

        for (int i = 0, length = nums.size(); i < length - 2; i++)
        {
            int left = i + 1, right = length - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(target - sum) < abs(target - closest))
                    closest = sum;
                if (sum < target)
                    ++left;
                else
                    --right;
            }
        }

        return closest;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums{-1, 2, 1, -4};
        assert(s.threeSumClosest(nums, 1) == 2);
    }
    {
        vector<int> nums{1, 1, -1, -1, 3};
        assert(s.threeSumClosest(nums, -1) == -1);
    }
}
