class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] != nums[i-1]) {  // Skip plateaus
                int left = nums[i-1];
                int right = nums[i+1];
                while (right == nums[i] && i+1 < nums.size()-1) {
                    i++;
                    right = nums[i+1];
                }
                if ((nums[i] > left && nums[i] > right) || 
                    (nums[i] < left && nums[i] < right)) {
                    count++;
                }
            }
        }
        return count;
    }
};