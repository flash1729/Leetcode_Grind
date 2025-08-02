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
//     if (node1 == null && node2 == null) {
// return true;
// }
// if (node1 == null || node2 == null) {
// return false;
// }
/* 
        if (node1 == null && node2 == null) {
        return true;
        }
        if (node1 == null || node2 == null) {
        return false;
        }
    this can be simplified to
     if (node1 == null || node2 == null) {
     return node1 == node 2;
    } 
*/
    bool check(TreeNode* r1, TreeNode* r2){
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;

        return (r1->val == r2->val) && check(r1->left,r2->right) && check(r1->right,r2->left);
    }
    

    bool isSymmetric(TreeNode* root) {
         
        return check(root->left,root->right);
    }
};