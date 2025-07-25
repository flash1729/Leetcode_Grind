class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxSum = nums[0];
        unordered_map<int,int> freq;
        freq[nums[0]]++;
        int sum = 0;

        for(int i = 1;i < nums.size();i++){
            if(freq[nums[i]] > 0) continue;
            freq[nums[i]]++;

            if(maxSum + nums[i] < nums[i] && maxSum < nums[i]){
                maxSum = nums[i];
                continue;
            }
            
            sum = maxSum;
            sum += nums[i];
            if(sum > maxSum){
                maxSum = sum;
            }
        }

        return maxSum;
    }
};