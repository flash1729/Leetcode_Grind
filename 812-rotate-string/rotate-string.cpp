class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
            return false;

        int n = s.size();

        for(int i = 0;i < n;i++){
            if(s == goal)
                return true;
            
            s = s.substr(1,n) + s[0];
        }

        return false;
    }
};