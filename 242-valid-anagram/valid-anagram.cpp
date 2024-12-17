class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        int a[26],b[26];

        for(int i = 0; i < s.length();i++){
            a[s[i] - 'a']++;
            b[t[i] - 'a']++;
        }

        for(int i = 0;i < 26;i++){
            if(a[i] != b[i])
                return false;
        }

        return true;
    }
};