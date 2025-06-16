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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> list;

        ListNode* temp = head;

        while(temp){
            list.push_back(temp);
            temp = temp->next;
        }

        int index = list.size() - n;

        if(index == 0){
            return head->next;
        }

        if(index == list.size() - 1){
            list[index - 1]->next = 0;
        }
        
        list[index-1]->next = list[index]->next;

        return head;
    }
};