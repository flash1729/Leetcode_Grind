class Solution {
public:
    struct greater{
        bool operator()(const vector<int> &a,const vector<int> &b){
            long long a1 = a[0]*a[0] + a[1]*a[1];
            long long a2 = b[0]*b[0] + b[1]*b[1];
            return a1 < a2;
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<vector<int>,vector<vector<int>>,greater> pq;
        vector<vector<int>> ans;

        for(auto a : points){
            pq.push(a);
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};