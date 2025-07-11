class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int res = 1;
        int ans = 1;
        for(int i = 0;i < nums.size() - 1;i++){
            if(nums[i] == nums[i+1]) continue;

            if(nums[i] + 1 == nums[i+1]){
                ans++;
                cout<<nums[i]<<" "<<ans<<endl;
            }else{
                res = max(res,ans);
                ans = 1;
            }
        }
        
        res = max(res,ans);

        return res;
    }
};