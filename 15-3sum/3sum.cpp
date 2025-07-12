class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        for(int i = 0; i < nums.size(); i++){

            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int target = -1 * nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            
            while(l < r && l < nums.size()){
                int cur = nums[l] + nums[r];
                
                if(cur > target){
                    r--;
                }else if(cur < target){
                    l++;
                }else{
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while(l < r && nums[l]==nums[l+1]) l++;
                    while(l < r && nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                }
            }
        }

        return ans;
    }
};