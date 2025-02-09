class Solution {
public:
    long long rev(int x){
        long long test = 0;
        while(x != 0){
            test = 10*test + (x%10);
            x = x / 10;
        }

        return test;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<long long,long long> res;
        long long n = nums.size();
        long long nicePair = 0;

        for(int i = 0;i < n;i++){
            res[nums[i] - rev(nums[i])]++;
        }

        for(auto& [diff, freq] : res){
            nicePair += (long long)freq * (freq - 1) / 2;
        }

        int ans = (int) (nicePair % (long long)(pow(10,9) + 7));

        return ans;
    }
};