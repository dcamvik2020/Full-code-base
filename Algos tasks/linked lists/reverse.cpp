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

   
/*
ListNode* reverseList(ListNode* head) {
  std::vector<int> values;
        
  int i;
  ListNode * tmp = head;
  for ( ; tmp; tmp = tmp->next)
    values.push_back(tmp->val);
  for (i = 0, tmp = head; tmp; tmp = tmp->next, ++i)
    tmp->val = values[values.size() - 1 - i];
  return head;
}
*/

ListNode* reverseList(ListNode* head) {
  if (head == nullptr)
    return head;
        
  ListNode * prev = nullptr;
  ListNode * cur  = head;
  ListNode * next = head -> next;
        
  while (next)
  {
    cur -> next = prev;
    prev = cur;
    cur = next;
    next = next -> next;            
  }
  cur -> next = prev;
  return head = cur;
}

