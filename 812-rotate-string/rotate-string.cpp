class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
            return false;

        int n = s.size();
        string temp = s;

        for(int i = 0;i < n;i++){
            if(temp == goal)
                return true;
            
            temp = temp.substr(1,n) + temp[0];
        }

        return false;
    }
};