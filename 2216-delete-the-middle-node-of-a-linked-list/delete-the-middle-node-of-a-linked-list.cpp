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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == 0){
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        cout<<slow->val<<endl;

        if(slow->next){
        slow->val = slow->next->val;
        slow->next = slow->next->next;
        }
        else{
            cout<<"here"<<endl;
            // slow = nullptr;
            head->next = nullptr;
        }
        
        return head;
    }
};