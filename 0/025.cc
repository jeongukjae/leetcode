// 25. Reverse Nodes in k-Group
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reverseGroup(ListNode* anchor, ListNode* node) {
    ListNode* temp;
    ListNode* previous = anchor;
    ListNode* current = anchor->next;
    ListNode* target = node->next;

    while (current != target) {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* anchor = head;
        ListNode* node = head;
        ListNode* previous = nullptr;
        ListNode* temp;

        bool isFirst = true;
        int count = 1;

        while (node != nullptr) {
            if (count == k) {
                temp = node->next;
                reverseGroup(anchor, node);

                // wire previous node and next node
                anchor->next = temp;
                if (previous != nullptr)
                    previous->next = node;

                // change head if required;
                if (isFirst) {
                    head = node;
                    isFirst = false;
                }

                // reset states
                previous = anchor;
                count = 1;
                node = anchor->next;
                anchor = node;
            } else {
                node = node->next;
                count++;
            }
        }

        return head;
    }
};
