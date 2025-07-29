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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        if(root == 0) return {};

        vector<int> res;
        TreeNode* curr = root;

        while(curr != 0 || !s.empty()){

            while(curr != 0){
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }

        return res;

        return res;
    }
};