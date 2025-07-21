class Solution {
public:
    bool isValid(vector<int> &blday,int mid, int m, int k){
        int count = 0;
        int adjFlowers = 0;
        for(int i = 0;i < blday.size();i++){

            if(blday[i] - mid <= 0){
                adjFlowers++;
            }else{
                count += adjFlowers / k;
                adjFlowers = 0;
            }
            if(count >= m) return true;
        }

        count += adjFlowers / k;
        
        return count >= m ? true : false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int blmax = INT_MIN;;

        for(int a : bloomDay){
            blmax = max(blmax,a);
        }

        int l = 1;
        int r = blmax;
        int res = INT_MAX;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(isValid(bloomDay,mid,m,k)){
                res = min(mid,res);
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};