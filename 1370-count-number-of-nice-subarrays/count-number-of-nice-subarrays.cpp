class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0;
        int res = 0;
        unordered_map<int,int> freq;
        freq[0] = 1;
        int currentCount = 0;

        for(int j = 0; j < nums.size();j++){
            if(nums[j] % 2 == 1){
                currentCount += 1;
            }

            int lookout = currentCount - k;
            res += freq[lookout];

            freq[currentCount]++;
        }

        return res;
    }
};