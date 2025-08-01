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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;

        if(root == nullptr){
            return {};
        }

        vector<vector<int>> res;

        q.push(root);
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            vector<int> cur(n);

            for(int i = 0;i < n;i++){
                TreeNode* temp = q.front();
                q.pop();

                if(level % 2 == 1){
                    cur[i] = temp->val;
                }else{
                    cur[n-1-i] = temp->val;
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            res.push_back(cur);
            level++;
        }

        return res;
    }
};