class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> ind;
        int n = nums.size();
        if(n == 1) return {-1};

        for(int i = n - 2;i >= 0; i--){
            ind.push(i);
        }

        vector<int> res(n);

        for(int i = n - 1;i >= 0;i--){
            while(!ind.empty() && nums[ind.top()] <= nums[i]){
                ind.pop();
            }

            if(ind.empty()){
                res[i] = -1;
            }else{
                res[i] = nums[ind.top()];
            }

            ind.push(i);
        }

        return res;
    }
};