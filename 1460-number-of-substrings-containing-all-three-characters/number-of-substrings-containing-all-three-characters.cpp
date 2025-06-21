class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> counts(3,0);

        int i = 0;
        int res = 0;

        for(int j = 0;j < s.size();j++){
            cout<<s[j] - 'a'<<endl;
            counts[s[j] - 'a']++;

            if(counts[0] > 0 && counts[1] > 0 && counts[2] > 0){
                res += s.size() - j;
            }
            
            while(counts[0] > 0 && counts[1] > 0 && counts[2] > 0){
                counts[s[i] - 'a']--;
                i++;
                if(counts[0] >= 1 && counts[1] >= 1 && counts[2] >= 1){
                    res += s.size() - j;
                }
            }
        }
        
        return res;
    }
};