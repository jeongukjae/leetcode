// 23. Merge k Sorted Lists
#include <vector>

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = nullptr, *current = nullptr;
        int listSize = lists.size();

        while (true)
        {
            int nextIndex = -1;

            for (int i = 0; i < listSize; i++)
            {
                ListNode *item = lists[i];

                if (item == nullptr)
                    continue;

                if (nextIndex == -1 || lists[nextIndex]->val > item->val)
                    nextIndex = i;
            }

            if (nextIndex == -1)
                break;
            else if (head == nullptr)
                head = current = lists[nextIndex];
            else
            {
                current->next = lists[nextIndex];
                current = current->next;
            }
            lists[nextIndex] = lists[nextIndex]->next;
        }

        return head;
    }
};
