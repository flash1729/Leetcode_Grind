class Solution {
public:
    bool check(int mid,vector<int> arr,int d){
        int ans = 1;

        int sum = 0;

        for(int i = 0;i < arr.size(); i++){
            
            if(arr[i] > mid) return false;

            if(sum + arr[i] > mid){
                ans++;
                sum = arr[i];
            }else{
                sum += arr[i];
            }

            if(ans > d) return false;
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int large = 0;
        for(int a : weights){
            large += a;
        }

        int l = 1;
        int r = large;

        int res = large;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(check(mid,weights,days)){
                res = min(mid,res);
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return res;
    }
};