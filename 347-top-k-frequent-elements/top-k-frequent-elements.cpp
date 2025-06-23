class Solution {
public:
    struct greater{
        bool operator()(pair<int,int> a,pair<int,int> b) const {
            return a.first > b.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> result;

        for(int i = 0;i < nums.size();i++){
            freq[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater> pq;

        for(const auto& a : freq){
            if(pq.size() < k){
                pq.push({a.second,a.first});
            }else{
                int test = pq.top().first;
                if(test < a.second){
                    pq.pop();
                    pq.push({a.second,a.first});
                }
            }
        }
        
        while(pq.empty() ==  false){
            pair<int,int> a = pq.top();
            result.push_back(a.second);
            pq.pop();
        }

        return result;
    }
};