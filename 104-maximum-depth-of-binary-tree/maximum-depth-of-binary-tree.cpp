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
    void maxD(TreeNode* root,int& depth,int cur){
        if(root != nullptr){
            cur++;
            depth = max(depth,cur);

            maxD(root->left,depth,cur);
            maxD(root->right,depth,cur);
        }
    }

    int maxDepth(TreeNode* root) {
        int depth = 0;

        maxD(root,depth,0);

        return depth;


    }
};