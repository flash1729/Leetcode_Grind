class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minIndex = 0;
        int maxDif = INT_MIN;

        for(int i = 1;i < nums.size();i++){
            int dif = nums[i] - nums[minIndex];
            maxDif = max(dif,maxDif);

            if(nums[i] < nums[minIndex]){
                minIndex = i;
            } 
        }
        
        if(maxDif <= 0){
            return -1;
        }

        return maxDif;
    }
};