#pragma once

#include <string>
#include <iterator>

class ReverseWords
{
public:
    class Solution
    {
    public:
        void reverseWords(string &s)
        {
            auto frontIt = s.begin();
            while (frontIt != s.end() && *frontIt == ' ')
                frontIt = s.erase(frontIt);

            auto backIt = s.rbegin();
            while (backIt != s.rend() && *backIt == ' ')
                backIt = reverse_iterator<string::iterator>(
                    s.erase(prev(backIt.base())));

            frontIt = s.begin();
            backIt = s.rbegin();
            while (frontIt != s.end() && backIt != s.rend() &&
                frontIt < prev(backIt.base()))
            {
                swap(*frontIt, *backIt);
                ++frontIt;
                ++backIt;
            }

            auto frontWordIt = s.begin();
            auto backWordIt = s.begin();
            int spaceN = 0;
            while (backWordIt != s.end())
            {
                if (*backWordIt == ' ')
                {
                    reverseWord(s, frontWordIt, prev(backWordIt));
                    spaceN++;
                }
                else
                {
                    ++backWordIt;
                    spaceN = 0;
                }

                if (spaceN > 1) frontWordIt = s.erase(frontWordIt);
            }
        }

        void reverseWord(string& s, string::iterator frontIt,
                                    string::iterator backIt)
        {

        }
        
    };

    static void test()
    {
        string str("  the sky is blute ");
        Solution s;
        s.reverseWords(str);
        cout << "#1 Reverse -> " << str.c_str() << endl;
    }
};
