class Solution {
public:
    bool check(long long mid,vector<int>& piles,int h){
        long long hours = 0;
        for(int a : piles){
            long long hr = a / mid;
            hours += hr;
            if(hr*mid < a){
                hours++;
            }
            if (hours > h) return false;
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0;
        long long largest = INT_MIN;

        for(int a : piles){
            sum += a;
            largest = max((long long)a,largest);
        }

        long long l = sum / (long long)h;
        if(l == 0) l++;
        
        long long r = largest;
        int ans = r;

        while(l <= r){
            long long mid = l + (r-l)/2;

            if(check(mid,piles,h)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }


        return ans;
    }
};