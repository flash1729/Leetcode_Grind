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
    struct greater{
        bool operator()(const pair<int,vector<pair<int,int>>>& a, const pair<int,vector<pair<int,int>>>& b){
            return a.first > b.first;
        }
    };

    struct smaller{
        bool operator()(const pair<int,int> &a,const pair<int,int> &b){
            if(a.first == b.first){
                return a.second > b.second;
            }

            return a.first > b.first;
        }
    };

    void preorder(TreeNode* root, int column,unordered_map<int,vector<pair<int,int>>>& map,int h){
        if(root == nullptr) return;

        int temp1 = column - 1;
        int temp2 = column + 1;
        int t3 = h + 1;

        map[column].push_back({h, root->val});
        preorder(root->left,temp1,map,t3);
        preorder(root->right,temp2,map,t3);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,vector<pair<int,int>>> vert;
        vector<vector<int>> res;

        preorder(root,0,vert,0);

        priority_queue<pair<int, vector<pair<int,int>>>, vector<pair<int, vector<pair<int,int>>>>, greater> pq;

        for(auto a : vert){
            pq.push({a.first, a.second});
        }

        while(!pq.empty()){
            vector<pair<int,int>> cur = pq.top().second;
            vector<int> temp;
            priority_queue<pair<int,int>, vector<pair<int,int>>, smaller> prq;
            for(auto a : cur){
                prq.push(a);
            }

            while(!prq.empty()){
                temp.push_back(prq.top().second);
                prq.pop();
            }

            res.push_back(temp);
            pq.pop();
        }

        return res;
    }
};