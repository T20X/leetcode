#pragma once

#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

namespace wiggle {

    class Solution {
    public:
        int wiggleMaxLength(vector<int>& nums)
        {
            if (nums.size() < 2)
                return nums.size();

            bool firstRun = true;
            bool lastPositive = false;//undefinied really!
                        
            auto currentIt = ++nums.begin();
            while (currentIt != nums.end())
            {
                auto prevIt = prev(currentIt);
                bool currentPositive = false;

                if (*currentIt - *prevIt < 0)                
                    currentPositive = false;
                
                if (*currentIt - *prevIt > 0)
                    currentPositive = true;

                if (firstRun)
                {
                    lastPositive = currentPositive;
                    firstRun = false;
                    ++currentIt;
                }
                if (lastPositive == currentPositive)
                {
                    currentIt = nums.erase(currentIt);
                }
                else 
                {
                    lastPositive = currentPositive;
                    ++currentIt;
                }
            }

            return nums.size();
        }

        void test()
        {
            vector<int> s = { 1, 9 };
            cout << wiggleMaxLength(s) << endl;
        }
    };

}