class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long resComp = 0;
        long long n = nums.size();

        unordered_map<int,int> res;

        for(int i = 0;i < n;i++){
            res[i - nums[i]]++;
        }

        for(auto& [diff, freq] : res) {
            resComp += (long long)freq * (freq - 1) / 2;
        }

        return (n*(n-1) / 2 ) - resComp;
    }
};