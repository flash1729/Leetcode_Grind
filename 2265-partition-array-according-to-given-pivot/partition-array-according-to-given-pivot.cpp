// class Solution {
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         int i = -1,j = 0;

//         for(;j < nums.size();j++){
//             if(nums[j] <= pivot){
//                 swap(nums[++i],nums[j]);
//             }
//         }

//         // if(i++ <= nums.size() - 1){
//         //     swap(nums[j],nums[++i]);
//         // }

//         return nums;
//     }
// };

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less_than, equal_to, greater_than;
    
    for (int num : nums) {
        if (num < pivot) 
            less_than.push_back(num);
        else if (num == pivot) 
            equal_to.push_back(num);
        else 
            greater_than.push_back(num);
    }
    
    vector<int> result;
    result.insert(result.end(), less_than.begin(), less_than.end());
    result.insert(result.end(), equal_to.begin(), equal_to.end());
    result.insert(result.end(), greater_than.begin(), greater_than.end());
    
    return result;
    }
};