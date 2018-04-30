#pragma once
#include <stdlib.h>

namespace listintersection
{
  
    struct ListNode {
        int val;
        ListNode *next;
       ListNode(int x) : val(x), next(0) {}
    };
   
    class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
        {
            size_t aLen = 0;
            size_t bLen = 0;
            ListNode* a = headA;
            ListNode* b = headB;
            while (a || b)
            {
                if (a)
                {
                    aLen++;
                    a = a->next;
                }

                if (b)
                {
                    bLen++;
                    b = b->next;
                }
            }

            a = headA;
            b = headB;
            if (aLen > bLen)
            {
                for (int i = 0; i < (aLen - bLen); i++)
                    a = a->next;
            }
            else if (bLen > aLen)
            {
                for (int i = 0; i < (bLen - aLen); i++)
                    b = b->next;
            }

            while (a && b)
            {
                if (a == b) return a;
                a = a->next;
                b = b->next;
            }

            return 0;
        }

        static void test()
        {
            Solution s;
        }
    };
}
