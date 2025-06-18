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
    ListNode* rotateRight(ListNode* head, int k) {
        //coding the bruteforce one
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        vector<ListNode*> list;

        ListNode*temp = head;

        while(temp){
            list.push_back(temp);
            temp = temp->next;
        }

        k = k % list.size();
        if(k == 0){
            return head;
        }

        int index = list.size() - k;

        ListNode* newHead = list[index];
        list[index - 1]->next = nullptr;
        list[list.size() - 1]->next = list[0];

        return newHead;
    }
};