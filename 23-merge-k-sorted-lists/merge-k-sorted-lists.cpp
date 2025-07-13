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
    struct greater{
        bool operator()(const ListNode* a, const ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,greater> pq;

        for(auto a : lists){
            if(a != nullptr){
                pq.push(a);
            }
        }
        ListNode* dhead = new ListNode();
        ListNode* temp = dhead;
        
        while(!pq.empty()){
            ListNode* cur = pq.top();
            temp->next = cur;
            temp = temp->next;

            if(cur != nullptr){
                pq.pop();
                if(cur->next != nullptr){
                    pq.push(cur->next);
                }
                continue;
            }
            pq.pop();
        }

        return dhead->next;
    }
};