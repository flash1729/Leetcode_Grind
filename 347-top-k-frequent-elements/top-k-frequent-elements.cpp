class Solution {
public:
    struct greater {
        bool operator()(const auto& a1, const auto& a2) const {
        return a1.second < a2.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> result;

        for(int i = 0;i < nums.size();i++){
            freq[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater> pq;

        for(auto& a : freq){
            pq.push({a.first,a.second});
        }

        for(int i = 0;i < k;i++){

            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};