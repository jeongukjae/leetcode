// 21. Merge Two Sorted Lists

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr && l2 == nullptr)
            return nullptr;
        else if (l1 == nullptr)
            return l2;
        else if (l2 == nullptr)
            return l1;

        ListNode *head, *current;

        if (l1->val <= l2->val)
        {
            current = head = l1;
            l1 = l1->next;
        }
        else
        {
            current = head = l2;
            l2 = l2->next;
        }

        while (l1 != nullptr || l2 != nullptr)
        {
            if (l2 == nullptr || (l1 != nullptr && l1->val <= l2->val))
            {
                current->next = l1;
                current = current->next;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                current = current->next;
                l2 = l2->next;
            }
        }

        return head;
    }
};
