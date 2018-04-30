#pragma once

#include <algorithm>
#include <vector>

using namespace std;

class Sum3Smaller
{
public:
    /*
    Given an array of n integers nums and a target, find the number of index triplets i, j, k 
    with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

    For example, given nums = [-2, 0, 1, 3], and target = 2.
    Return 2. Because there are two triplets which sums are less than 2:
    [-2, 0, 1]
    [-2, 0, 3]

    Follow up:
    Could you solve it in O(n2) runtime?
    */
    class Solution
    {
    public:
        int threeSumSmaller(vector<int>& nums, int target)
        {
            std::sort(nums.begin(), nums.end());

            int solution = 0;
            int len = nums.size();

            int i = 0;
            int j = 1;
            int k = len - 1;
            while (i < j)
            {                
                while (j < k)
                {
                    int localTarget = target - nums[i];
                    int jkSum = nums[j] + nums[k];
                    if (jkSum < localTarget)
                    {
                        solution += (k - j);
                        j++;
                    }
                    else
                    {
                        k--;
                    }
                }

                i++;
                k = len - 1;
                j=std::min(i+1, k-1);
                
            }

            return solution;
        }
    };

    static void test()
    {
        Solution s;
        std::cout << "#1 -> " << s.threeSumSmaller(std::vector<int>({ -2, 0, 1, 3 }), 2) << std::endl;
    }
};
