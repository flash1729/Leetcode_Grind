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
    bool isPalindrome(ListNode* head) {
        if(head == 0 || head->next == 0){
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != 0 && fast->next != 0){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;

        while(slow != 0){
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while(second){
            if(first->val != second->val) return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};