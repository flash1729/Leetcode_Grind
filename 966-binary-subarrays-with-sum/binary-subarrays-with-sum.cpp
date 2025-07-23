class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0;
        int res = 0;
        unordered_map<int,int> pSum;
        pSum[0] = 1;
        int currentSum = 0;
        
        for(int j = 0;j < nums.size();j++){
            currentSum += nums[j];
            int lookup = currentSum - goal;
            res += pSum[lookup];

            pSum[currentSum]++;
        }

        return res;
    }
};