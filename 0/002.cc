// 2. Add Two Numbers
//
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *rootNode = new ListNode;
        ListNode *current = rootNode;
        bool l1Ended = false, l2Ended = false;
        int carry = 0;

        while (true)
        {
            int l1Element = 0, l2Element = 0;
            if (!l1Ended)
                l1Element = l1->val;
            if (!l2Ended)
                l2Element = l2->val;

            int value = l1Element + l2Element + carry;

            ListNode *tmp = new ListNode(value % 10);
            current->next = tmp;
            current = tmp;
            carry = value / 10;

            if (l1->next != nullptr)
                l1 = l1->next;
            else
                l1Ended = true;

            if (l2->next != nullptr)
                l2 = l2->next;
            else
                l2Ended = true;

            if (l1Ended && l2Ended && carry == 0)
                break;
        }

        return rootNode->next;
    }
};
