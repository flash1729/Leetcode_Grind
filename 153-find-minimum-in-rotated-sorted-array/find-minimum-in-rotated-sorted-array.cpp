class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int res = INT_MAX;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[l] <= nums[mid]) {
                // Left half [l...mid] is sorted
                // Minimum is either nums[l] or in right half
                res = min(res,nums[l]);
                l = mid + 1;
            } else {
                // Left half is unsorted (contains rotation point)
                // Minimum is in left half
                res = min(res, nums[mid]);
                r = mid - 1;
            }
        }

        return res;
    }
};