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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int res = 1;

        while(!q.empty()){
            int itr = q.size();
            long long left_node = 0;
            long long right_node = 0;

            long long level_min_index = q.front().second;

            for(int i = 0;i < itr; i++){
                
                pair<TreeNode*,long long> curNode = q.front();
                q.pop();
                if(i == 0){
                    left_node = curNode.second;
                }

                if(i == itr - 1){
                    right_node = curNode.second;
                }

                if(curNode.first->left != nullptr){
                    q.push({curNode.first->left,(curNode.second - level_min_index)*2 + 1});
                }

                if(curNode.first->right != nullptr){
                    q.push({curNode.first->right,2*(curNode.second - level_min_index) + 2});
                }
            }
            int cur = right_node - left_node + 1;
            res = max(cur,res);
        }

        return res;
    }
};