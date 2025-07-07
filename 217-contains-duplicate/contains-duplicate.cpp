class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        
        for(int a : nums){
            freq[a]++;
            if(freq[a] == 2)
                return true;
        }

        return false;
    }
};