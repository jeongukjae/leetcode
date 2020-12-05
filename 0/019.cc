// 19. Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int i = 0;
        vector<ListNode *> nodeVector;
        nodeVector.reserve(30);
        ListNode *current = head;

        while (current != nullptr)
        {
            nodeVector.push_back(current);
            current = current->next;
        }

        n = nodeVector.size() - n;
        if (n == 0)
            return head->next;

        if (n == nodeVector.size() - 1)
            nodeVector[n - 1]->next = nullptr;
        else
            nodeVector[n - 1]->next = nodeVector[n + 1];

        return head;
    }
};
