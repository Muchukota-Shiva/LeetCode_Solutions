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
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has only one element, it is already sorted.
        if (!head || !head->next) return head;

        // Use the fast and slow pointer approach to find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        } // new concept try to remember 

        // Split the list into two halves
        ListNode* midNext = slow->next;
        slow->next = nullptr;
      
        // Recursively sort both halves
        ListNode* leftHalf = sortList(head);
        ListNode* rightHalf = sortList(midNext);
      
        // Merge the two sorted halves
        ListNode* dummyHead = new ListNode();
        ListNode* current = dummyHead;
        while (leftHalf && rightHalf) {
            // Choose the smaller value from either half
            if (leftHalf->val <= rightHalf->val) {
                current->next = leftHalf;
                leftHalf = leftHalf->next;
            } else {
                current->next = rightHalf;
                rightHalf = rightHalf->next;
            }
            // Move to the next node in the merged list
            current = current->next;
        }
      
        // If there are remaining nodes in either half, append them to the merged list
        current->next = leftHalf ? leftHalf : rightHalf; // this was causing errors
      
        // The merged sorted list is pointed to by the dummy head's next node
        ListNode* sortedHead = dummyHead->next;
        delete dummyHead; // Clean up the dummy node
        return sortedHead;
    }
};