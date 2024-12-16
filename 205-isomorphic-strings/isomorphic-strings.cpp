class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> s_t,t_s;

        int n = s.length();
        for(int i = 0;i < n;i++){
            if(s_t.count(s[i]) == 1){
                if(s_t[s[i]] != t[i]){
                    return false;
                }
            }
            else{
                if(t_s.count(t[i]) == 1)
                    return false;
                s_t[s[i]] = t[i];
                t_s[t[i]] = s[i];
            }

            
        }

        return true;
    }
};