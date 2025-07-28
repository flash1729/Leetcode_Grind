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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;

        if(root == 0) return {};
        vector<int> res;
        s.push(root);

        while(!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            res.push_back(cur->val);

            if(cur->right != 0){
                s.push(cur->right);
            }

            if(cur->left != 0){
                s.push(cur->left);
            }
        }

        return res;
    }
};