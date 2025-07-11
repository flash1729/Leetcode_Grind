class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0,j = numbers.size() - 1;

        while(i < j){
            int cur = numbers[i] + numbers[j];

            if(cur < target){
                i++;
            }
            else if(cur > target){
                j--;
            }
            else{
                break;
            }
        }

        return {i+1,j+1};
    }
};