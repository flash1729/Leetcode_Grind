/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void returnPath(TreeNode* root,vector<TreeNode*> &path,vector<TreeNode*> &p,TreeNode* node){
        if(root == nullptr) return;

        if(node->val == root->val){
            path.push_back(root);

            p = path;
            return;
        }

        path.push_back(root);
        returnPath(root->left,path,p,node);
        returnPath(root->right,path,p,node);

        path.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1;
        vector<TreeNode*> p2;

        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        returnPath(root,path1,p1,p);
        returnPath(root,path2,p2,q);

        int i = 0;
        int j = min(p1.size(),p2.size());

        while(i < j && (p1[i]->val == p2[i]->val)){
            i++;
        }

        return p1[i-1];
    }
};