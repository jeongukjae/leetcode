// 24. Swap Nodes in Pairs
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* previous = nullptr;
        ListNode* current = head;
        ListNode* next = current->next;
        ListNode* temp;
        head = next;

        while (current != nullptr && next != nullptr) {
            current->next = next->next;
            next->next = current;
            if (previous != nullptr)
                previous->next = next;

            previous = current;
            current = current->next;
            if (current != nullptr)
                next = current->next;
        }

        return head;
    }
};
