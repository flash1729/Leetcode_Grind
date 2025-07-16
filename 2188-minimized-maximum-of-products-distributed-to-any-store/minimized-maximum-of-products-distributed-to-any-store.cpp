class Solution {
public:
    bool check(int mid,vector<int>& arr,int n){
        int ans = 0;
        for(int a : arr){
            if(mid == 0 && a != 0) return false;
            int quo = a / mid;
            ans += quo;
            if(a > quo*mid) ans++;
            if(ans > n) return false;
        }

        return true;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int large = INT_MIN;
        for(int a : quantities){
            large = max(a,large);
        }

        int l = 0;
        int r = large;

        int res = large;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(check(mid,quantities,n)){
                res = min(mid,res);
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return res;
    }
};