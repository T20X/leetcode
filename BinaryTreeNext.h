#pragma once

namespace binarytreenext
{
    struct TreeLinkNode {
        int val;
       TreeLinkNode *left, *right, *next;
       TreeLinkNode(int x) : val(x), left(0), right(0), next(0) {}
   };

    class Solution {
    public:
        void connect(TreeLinkNode *root)
        {                 
            TreeLinkNode* tail = root;
            TreeLinkNode* head = 0;
            TreeLinkNode* current = 0;
            TreeLinkNode* prev = 0;

            while (tail != 0)
            {
                //process level
                while (tail != 0)
                {
                    if (tail->left)
                    {
                        if (!head)
                            head = tail->left;

                        if (!prev)
                            prev = tail->left;

                        current = tail->left;
                        if (current != prev)
                        {
                            prev->next = current;
                            prev = current;
                        }
                    }

                    if (tail->right)
                    {
                        if (!head)
                            head = tail->right;

                        if (!prev)
                            prev = tail->right;

                         current = tail->right;
                         if (current != prev)
                         {
                             prev->next = current;
                             prev = current;
                         }                        
                    }

                    tail = tail->next;
                }

                tail = head;
                prev = current = head = 0;                
            }
        }

        static void test()
        {
            Solution s;

            // root
            TreeLinkNode* root = new TreeLinkNode(100);                        

            //1 level
            TreeLinkNode*  left1st = new TreeLinkNode(90);
            TreeLinkNode*  right1st = new TreeLinkNode(120);
            root->left = left1st;
            root->right = right1st;

            //2 level
            TreeLinkNode*  left1_1st = new TreeLinkNode(80);
            TreeLinkNode*  right1_1st = new TreeLinkNode(85);
            TreeLinkNode*  left2_1st = new TreeLinkNode(118);
            TreeLinkNode*  right2_1st = new TreeLinkNode(125);
            left1st->left = left1_1st;
            left1st->right = right1_1st;
            right1st->left = left2_1st;
            right1st->right = right2_1st;

            s.connect(root);
            int i = 0;
        }
    };
}
