class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }

        int ascSum = nums[0];
        int maxSum = nums[0];
        int n = nums.size();

        for(int i = 0;i < n - 1;i++){
           if(nums[i+1] > nums[i]){
                ascSum += nums[i+1];
           }
           else{
                maxSum = max(maxSum,ascSum);
                ascSum = nums[i+1];
           }
        }

        maxSum = max(maxSum, ascSum);

        return maxSum;
    }
};