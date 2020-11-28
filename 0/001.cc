// 1. Two Sum
//
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> tempMap; // required -> index

        for (int index = 0; index < nums.size(); index++)
        {
            int required = target - nums[index];

            if (tempMap.find(required) != tempMap.end())
            {
                return {tempMap[required], index};
            }
            else
            {
                tempMap[nums[index]] = index;
            }
        }

        return {0, 1};
    }
};

int main()
{
    Solution s;
    std::vector<int> nums{3, 2, 4};
    const auto &result = s.twoSum(nums, 6);
    for (auto e : result)
        std::cout << e << ", ";
    std::cout << std::endl;
}
