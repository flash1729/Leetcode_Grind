class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> freq;
        vector<int> res(2);

        for(int i = 0; i < nums.size();i++){
            int comp = target - nums[i];

            if(freq.count(comp)){
                res[0] = freq[comp];
                res[1] = i;
                break;
            }else{
                freq[nums[i]] = i; 
            }
        }

        return res;
    }
};