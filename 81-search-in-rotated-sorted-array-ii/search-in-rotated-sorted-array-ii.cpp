class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        
        while(i <= j){
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
            while(j > 0 && nums[j] == nums[j - 1]) j--;

            int mid = i + (j-i)/2;

            if(nums[mid] == target){
                return true;
            }
            else if(nums[i] <= nums[mid]){
                if(target >= nums[i] && target <= nums[mid]){
                    j = mid - 1;
                }else{
                    i = mid + 1;
                }
            }
            else{
                if(target <= nums[j] && target >= nums[mid]){
                    i = mid + 1;
                }else{
                    j = mid - 1;
                }
            }
        }

        return false;
    }
};