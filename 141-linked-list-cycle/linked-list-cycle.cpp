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
        set<ListNode*> count;
        ListNode* temp = head;
        while(temp != 0){
            if(count.contains(temp)){
                printf("Cycle Detected");
                return true;
            }
            count.insert(temp);
            temp = temp->next;
        }

        return false;
    }
};