/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    int find(Node* temp,vector<Node*> list){

        for(int i = 0;i < list.size();i++){
            if(temp == list[i]){
                return i;
            }
        }

        return 0;
    }

    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }

        Node* dh = new Node(-1);
        Node* t2 = dh;
        Node* t1 = head;
        vector<Node*> list1;
        vector<Node*> list2;

        while(t1){
            Node* newNode = new Node(t1->val);
            t2->next = newNode;
            
            t2 = newNode;
            list2.push_back(t2);
            list1.push_back(t1);

            t1 = t1->next;

        }

        t1 = head;
        t2 = dh->next;

        while(t1){
            if(!t1->random){
                t2->random = nullptr;
            }else{
            int index = find(t1->random, list1);
            t2->random = list2[index];
            }
            t1 = t1->next;
            t2 = t2->next;
        }

        Node* newhead = dh->next;

        delete dh;

        return newhead;
    }
};