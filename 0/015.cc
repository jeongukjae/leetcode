// 15. 3Sum

#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0, length = nums.size(); i < length - 2; i++)
        {
            int anchor = nums[i];
            // skip same values
            if (i > 0 && nums[i - 1] == anchor)
                continue;

            int left = i + 1, right = length - 1;
            while (left < right)
            {
                int summation = nums[left] + nums[right];
                if (summation > -anchor)
                    right--;
                else if (summation < -anchor)
                    left++;
                else
                {
                    result.push_back({anchor, nums[left], nums[right]});

                    // skip same values
                    do
                        left++;
                    while (left < right && nums[left] == nums[left - 1]);
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums{-1, 0, 1, 2, -1, -4};
        auto result = s.threeSum(nums);
    }
}
