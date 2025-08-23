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
    void evenSum(TreeNode* root, int parent, int grandparent, int &sum){
        if(root == nullptr) return;

        if(grandparent%2 == 0){
            sum += root->val;
        }

        evenSum(root->left,root->val,parent,sum);
        evenSum(root->right,root->val,parent,sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        evenSum(root,-1, -1, sum);

        return sum;
    }
};