// 18. 4Sum
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;

        std::sort(nums.begin(), nums.end());
        int length = nums.size();

        for (int i = 0, iLimit = length - 3; i < iLimit; i++)
        {
            for (int j = i + 1, jLimit = length - 2; j < jLimit; j++)
            {
                int start = j + 1, end = length - 1;
                int ijSum = nums[i] + nums[j];

                while (start < end)
                {
                    int sum = ijSum + nums[start] + nums[end];
                    if (sum == target)
                    {
                        result.push_back({nums[i], nums[j], nums[start], nums[end]});
                        do
                            start++;
                        while (start < end && nums[start] == nums[start - 1]);
                    }
                    else if (sum > target)
                        end--;
                    else
                        start++;
                }

                while (j < jLimit && nums[j] == nums[j + 1])
                    j++;
            }
            while (i < iLimit && nums[i] == nums[i + 1])
                i++;
        }

        return result;
    }
};
