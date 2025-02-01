class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 0;i < nums.size() - 1; i++){
            if(i+1 <= nums.size()){
                    if((nums[i] + nums[i+1]) % 2 != 1){
                        return false;
                    }
            }
        }
        return true;
    }
};