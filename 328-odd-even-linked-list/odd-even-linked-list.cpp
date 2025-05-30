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
    ListNode* oddEvenList(ListNode* head) {
        // man i forgot base cases
        if(head == 0 || head->next == 0|| head->next->next == 0){
            return head;
        }

        ListNode* oddT = head;
        ListNode* evenT = head->next;
        // i need to save odd tail and even head to join afterwards...
        ListNode* oddH = head; //wont change
        ListNode* evenH = head->next; // this will not change as well

        while(evenT && evenT->next){
            oddT->next = oddT->next->next;
            oddT = oddT->next;
            evenT->next = evenT->next->next;
            evenT = evenT->next;
        }

        oddT->next = evenH;
        if(evenT){
        evenT->next = nullptr;
        }

        return oddH;
    }
};