/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        
        ListNode * cur = head;
        ListNode * next = head -> next;
        ListNode * to_remove;
        while (next)
        {
            if (next -> val == cur -> val)
            {
                to_remove = next;
                cur -> next = next -> next;
                next = next -> next;
                to_remove -> next = nullptr;
                delete to_remove;
            }
            else
            {
                cur = next;
                next = cur -> next;
            }
        }
        return head;
    }
};
