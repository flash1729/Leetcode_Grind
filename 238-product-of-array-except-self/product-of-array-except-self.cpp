class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> prefix(nums.size() + 1);
        vector<int> suffix(nums.size() + 1);
        prefix[0] = 1;

        suffix[nums.size()] = 1;

        for(int i = 0;i < nums.size();i++){
            prefix[i+1] = prefix[i] * nums[i];
        }

        for(int i = nums.size() - 1;i >= 0;i--){
            suffix[i] = suffix[i + 1] * nums[i];
        }

        for(int i = 0; i < nums.size();i++){
            ans[i] = prefix[i] * suffix[i+1];
        }

        return ans;
    }
};