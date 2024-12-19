class Solution {
public:
    int maxDepth(string s) {
        int check = 0;
        int ans = 0;
        for(char a : s){
            if(a == '('){
                check ++;
                ans = max(ans,check);
            }
            else if(a == ')'){
                check --;
            }
        }
        return ans;
    }
};