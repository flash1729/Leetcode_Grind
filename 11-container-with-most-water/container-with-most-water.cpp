class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int i = 0;
        int j = height.size() - 1;

        while(i < j){
            int cur = min(height[i],height[j]) * (j - i);
            ans = max(ans,cur);

            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }

        return ans;
    }
};