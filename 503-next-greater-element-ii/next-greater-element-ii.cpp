class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> ind;
        int n = nums.size();

        vector<int> res(n);

        for(int i = 2*n - 1;i >= 0;i--){
            while(!ind.empty() && nums[ind.top() % n] <= nums[i % n]){
                ind.pop();
            }

            if(ind.empty()){
                res[i % n] = -1;
            }else{
                res[i % n] = nums[ind.top() % n];
            }

            ind.push(i);
        }

        return res;
    }
};