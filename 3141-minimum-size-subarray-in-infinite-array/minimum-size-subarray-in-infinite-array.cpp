class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long snum = 0;
        for (int num : nums) {
            snum += num;
        }


        if (target == snum) {
            return nums.size();
        }

        int minlen = INT_MAX;

                if (target < snum) {
            int i = 0, j = 0, curSum = 0;

            vector<int> extended(nums.begin(), nums.end());
            extended.insert(extended.end(), nums.begin(), nums.end());

            for (; j < extended.size(); j++) {
                
                curSum += extended[j];

                while (curSum > target && i <= j) {
                    curSum -= extended[i];
                    i++;
                }

                if (curSum == target && (j - i + 1) <= nums.size()) {
                    minlen = min(minlen, j - i + 1);
                }
            }
            if(minlen == INT_MAX){
                minlen = -1;
            }
        } else {
            int x = target / snum;
            target = target - x * snum;
            int sum = 0;
            int i = 0, j = 0, curSum = 0;
            int minsub = INT_MAX;

            vector<int> extended(nums.begin(), nums.end());
            extended.insert(extended.end(), nums.begin(), nums.end());

            for (; j < extended.size(); j++) {

                curSum += extended[j];

                while (curSum > target && i <= j) {
                    curSum -= extended[i];
                    i++;
                }

                if (curSum == target && (j - i + 1) <= nums.size()) {
                    minsub = min(minsub, j - i + 1);
                }
            }

            if (minsub != INT_MAX) {
                minlen = x * nums.size() + minsub;
            } else {
                minlen = -1;
            }
        }

        
        return minlen;
    }
};