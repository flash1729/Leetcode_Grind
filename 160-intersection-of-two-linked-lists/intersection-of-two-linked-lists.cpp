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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> l1;
        

        ListNode* temp = headA;
        while(temp){
            l1.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while(temp){
            if(l1.contains(temp)){
                return temp;
            }
            temp = temp->next;
        }

        // for(ListNode* x : l1){
        //     if(l2.contains(x)){
        //         return x;
        //     }
        // }

        return 0;
    }
};