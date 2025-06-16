class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minIndex = 0;
        int maxDif = INT_MIN;

        for(int i = 1;i < prices.size();i++){
            int dif = prices[i] - prices[minIndex];
            maxDif = max(dif,maxDif);

            if(prices[i] < prices[minIndex]){
                minIndex = i;
            } 
        }

        if(maxDif <= 0){
            return 0;
        }
        
        return maxDif;
    }
};