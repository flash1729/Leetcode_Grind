class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ops = 0;

    priority_queue<long long, vector<long long>, greater<long long>> res;

        for (int i = 0; i < nums.size(); i++) {
            res.push(nums[i]);
        }

        while(res.top() < k){
            long long a = res.top();
            res.pop();
            long long b = res.top();
            res.pop();
            ops++;
            res.push(2*min(a,b) + max(a,b));
        }

        return ops;
    }
};