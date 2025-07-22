class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> freq;
        int sum = 0;
        int j = 0;
        int cur = 0;

        for(int i = 0;i < nums.size();i++){
            freq[nums[i]]++;
            cur += nums[i];

            while(freq[nums[i]] > 1){
                cur -= nums[j];
                freq[nums[j]]--;
                j++;
            }

            sum = max(sum,cur);
        }

        return sum;
    }
};