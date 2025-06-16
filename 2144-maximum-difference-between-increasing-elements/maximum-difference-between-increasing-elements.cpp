class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        //brute force get all combinations
        int maxDif = INT_MIN;

        for(int i = 0;i < nums.size();i++){
            for(int j = i + 1;j < nums.size();j++){
                if(nums[j] > nums[i]){
                    int diff = nums[j] - nums[i];
                    maxDif = max(maxDif,diff);
                }
            }
        }
        if(maxDif == INT_MIN){
            return -1;
        }
        
        return maxDif;
    }
};