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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == 0) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;

        int itr = 1;
        int nextitr = 1;

        while(!q.empty()){
            vector<int> temp;
            itr = nextitr;
            nextitr = 0;
            
            for(int i = 0;i < itr;i++){
                TreeNode* cur = q.front();
                q.pop();
                
                temp.push_back(cur->val);

                if(cur->left != 0){
                    q.push(cur->left); 
                    nextitr++;
                }
                if(cur->right != 0){
                    q.push(cur->right);
                    nextitr++;
                }
            }
            res.push_back(temp);
        }

        return res;
    }
};