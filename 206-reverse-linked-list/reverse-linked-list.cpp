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
        if(head == nullptr){
            return nullptr;
        }
        vector<int> list;
        ListNode* temp = head;

        while(temp != nullptr){
            list.push_back(temp->val);
            temp = temp->next;
        }

        int n = list.size();
        ListNode* headR = new ListNode(list[n-1]);
        ListNode* tempR = headR;
        for(int i = n-2;i >= 0;i--){
            ListNode* nodeptr = new ListNode(list[i]);
            tempR->next = nodeptr;
            tempR = nodeptr;
        }

        return headR;
    }
};