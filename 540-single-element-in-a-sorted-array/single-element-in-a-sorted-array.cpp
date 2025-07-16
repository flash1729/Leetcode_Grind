class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            // Edge cases: mid is at boundary
            if (mid == 0 || mid == nums.size() - 1) return nums[mid];

            // Unique element condition: not matching either neighbor
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // Case 1: mid matches with previous element
            if (nums[mid] == nums[mid - 1]) {
                int left_count = mid - l + 1;
                if (left_count % 2 == 0) {
                    l = mid + 1;
                } else {
                    r = mid - 2;
                }
            }
            // Case 2: mid matches with next element
            else {
                int right_count = r - mid + 1;
                if (right_count % 2 == 0) {
                    r = mid - 1;
                } else {
                    l = mid + 2;
                }
            }
        }

        return -1;
    }
};
