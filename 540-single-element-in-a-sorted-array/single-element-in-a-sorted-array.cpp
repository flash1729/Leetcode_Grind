class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (mid == 0 || mid == nums.size() - 1) return nums[mid];

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            if (nums[mid] == nums[mid - 1]) {
                int left_count = mid - l + 1;
                if (left_count % 2 == 1)
                    r = mid - 2;
                else
                    l = mid + 1;
            } else {
                int right_count = r - mid + 1;
                if (right_count % 2 == 1)
                    l = mid + 2;
                else
                    r = mid - 1;
            }
        }

        return -1;
    }
};
