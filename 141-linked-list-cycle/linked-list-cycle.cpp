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
        ListNode* slow = head;
        ListNode* fast = head;

        if(head == 0){
            return false;
        }

        if(head->next == 0){
            return false;
        }

        while(fast != 0){
            slow = slow->next;
            if(fast->next == 0){
                break;
            }
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }

        return false;
    }
};