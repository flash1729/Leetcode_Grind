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
    ListNode* reverseList(ListNode* head) {
        if(head == 0 || head->next == 0){
            return head;
        }

        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* p3 = head;

        head->next = nullptr;
        
        while(cur != nullptr){
            p3 = cur->next;
            cur->next = prev;
            prev = cur;
            cur = p3;
        }

        return prev;
    }
};