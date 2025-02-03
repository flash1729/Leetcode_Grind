class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1,maxLen = 1;
        bool in = true,de = true;

        for(int i = 0;i < nums.size() - 1;i++){
            if(nums[i + 1] > nums[i]){
                inc += 1;
                dec = 1;

                maxLen = max(maxLen,inc);
            }
            else if(nums[i+1] < nums[i]){
                dec += 1;
                inc = 1;
                maxLen = max(maxLen,dec);
            }
            else{
                inc = 1;
                dec = 1;
            }
        }

        return maxLen;
    }
};