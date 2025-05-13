class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> unique_nums;
        for (int num : nums) {
            if (unique_nums.find(num) != unique_nums.end()) {
                return true;
            }
            unique_nums.insert(num);
        }
        return false;
    }
};