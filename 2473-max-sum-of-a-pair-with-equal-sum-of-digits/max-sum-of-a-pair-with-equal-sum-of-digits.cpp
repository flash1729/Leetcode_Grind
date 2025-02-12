class Solution {
public:
    int sumOfTerms(int n){
        int sum = 0;
        while(n > 0){
            sum += n %10;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> result;

        for(int i = 0;i < nums.size();i++){
            result[sumOfTerms(nums[i])].push_back(nums[i]);
        }

    int maxSum = -1;
    int sum = 0;

    for(auto &a : result){
        if(a.second.size() > 1){
            std::sort(a.second.begin(), a.second.end());

            int last = a.second.back();
            int second_last = a.second[a.second.size() - 2];
            
            sum = last + second_last;
            maxSum = max(maxSum,sum);
        }
    }
    return maxSum;
    
    }

    
};