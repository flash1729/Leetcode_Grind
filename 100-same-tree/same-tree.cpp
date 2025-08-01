/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        if((p == 0 && q != 0) || p != 0 && q == 0) return false;

        if((p == 0 && q == 0)) return true;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() || !q2.empty()){
            TreeNode* tp = q1.front();
            TreeNode* tq = q2.front();

            q1.pop();
            q2.pop();

            if(tp->val != tq->val) return false;

            if(tp->left){
                if(tq->left == nullptr) return false;

                q1.push(tp->left);
                q2.push(tq->left);
            }else if(tq->left){
                return false;
            }

            if(tp->right){
                if(tq->right == nullptr) return false;

                q1.push(tp->right);
                q2.push(tq->right);
            }else if(tq->right){
                return false;
            }
        }

        return true;
    }
};