/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slowPointer = head;
        ListNode *fastPointer = head;
      
        // Loop until the fast pointer reaches the end of the list
        while (fastPointer && fastPointer->next) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
            if (slowPointer == fastPointer) {
                return true;
            }
        }
        return false;
    }
};