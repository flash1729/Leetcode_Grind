class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> counts(3,0);

        int i = 0;
        int res = 0;

        for(int j = 0;j < s.size();j++){
            counts[s[j] - 'a']++;
            
            while(counts[0] > 0 && counts[1] > 0 && counts[2] > 0){
                res += s.length() - j;
                counts[s[i] - 'a']--;
                i++;
            }
        }
        
        return res;
    }
};