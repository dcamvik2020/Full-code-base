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

ListNode* reverseBetween(ListNode* head, int left, int right) {
  if (head == nullptr)
    return head;
  if (head -> next == nullptr)
    return head;
  
  ListNode * prev = nullptr;
  ListNode * cur  = head;
  ListNode * next = head -> next;
  
  for (int i = 1; i < left; ++i)
  {
    prev = cur;
    cur  = next;
    next = next -> next;
  }
  
  ListNode * first_to_reverse_prev = prev;
  ListNode * first_to_reverse = cur;
  for (int i = left; i < right; ++i)
  {
    cur -> next = prev;
    prev = cur;
    cur = next;
    next = next -> next;
  }
  cur -> next = prev;
  ListNode * last_to_reverse = cur;
  ListNode * last_to_reverse_next = next;
  
  if (first_to_reverse_prev == nullptr)
  {
    head = last_to_reverse;
  }
  else
  {
    first_to_reverse_prev -> next = last_to_reverse;
  }

  first_to_reverse -> next = last_to_reverse_next;
  
  return head;
}



