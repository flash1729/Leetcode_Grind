class Solution {
public:
    bool check(vector<int> &candies,int mid,long long k){
        long long count = 0;

        for(int a : candies){
            count += a / mid;
        }

        return count >= k ? true : false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        int maxCandies = INT_MIN;

        for(int a : candies){
            maxCandies = max(a,maxCandies);
            sum += a;
        }

        if(sum < k) return 0;

        int i = 1;
        int j = maxCandies;
        int res = 1;

        while(i <= j){
            int mid = i + (j - i)/2;

            if(check(candies,mid,k)){
                res = max(res,mid);
                i = mid + 1;
            }else{
                j = mid - 1;
            }
        }

        return res;
    }
};