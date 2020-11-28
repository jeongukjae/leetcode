// 4. Median of Two Sorted Arrays
//
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// Follow up: The overall run time complexity should be O(log (m+n)).
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int index1 = 0, index2 = 0;
        auto nums1Iterator = nums1.begin();
        auto nums2Iterator = nums2.begin();

        int totalLength = nums1.size() + nums2.size();
        bool isEven = totalLength % 2 == 0;
        int medianIndex = totalLength / 2 - (int)isEven;

        for (int i = 0; i < medianIndex; i++)
        {
            if (nums2Iterator == nums2.end() || (nums1Iterator != nums1.end() && *nums1Iterator < *nums2Iterator))
                nums1Iterator++;
            else
                nums2Iterator++;
        }

        double median;

        if (nums2Iterator == nums2.end() || (nums1Iterator != nums1.end() && *nums1Iterator < *nums2Iterator))
        {
            median = *nums1Iterator;
            nums1Iterator++;
        }
        else
        {
            median = *nums2Iterator;
            nums2Iterator++;
        }

        if (isEven)
        {
            if (nums2Iterator == nums2.end() || (nums1Iterator != nums1.end() && *nums1Iterator < *nums2Iterator))
                median += *nums1Iterator;
            else
                median += *nums2Iterator;
        }

        return median / (1.0 + (double)isEven);
    }
};

double getAnswer(vector<int> nums1, vector<int> nums2)
{
    Solution s;
    return s.findMedianSortedArrays(nums1, nums2);
}

int main()
{
    std::cout << getAnswer(vector<int>{1, 3}, vector<int>{2}) << std::endl;
    std::cout << getAnswer(vector<int>{1, 2}, vector<int>{3, 4}) << std::endl;
    std::cout << getAnswer(vector<int>{0, 0}, vector<int>{0, 0}) << std::endl;
    std::cout << getAnswer(vector<int>{}, vector<int>{2}) << std::endl;
    std::cout << getAnswer(vector<int>{2}, vector<int>{}) << std::endl;
}
