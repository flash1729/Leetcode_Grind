class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() <= 2) return s;
        
        string result = "";
        result += s[0];
        
        int consecutiveCount = 1;
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                consecutiveCount++;
            } else {
                consecutiveCount = 1;
            }
            
            if (consecutiveCount <= 2) {
                result += s[i];
            }
        }
        
        return result;
    }
};