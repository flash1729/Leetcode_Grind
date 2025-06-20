class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int res = 0;
        unordered_map<char,int> freq;
        int maxFreq = 0;

        for(int j = 0; j < s.length();j++){
            char right = s[j];
            freq[right]++;
            maxFreq = max(maxFreq, freq[right]);

            while(j-i+1 - maxFreq > k){
                freq[s[i]]--;
                i++;
            }

            res = max(res,j-i+1);

        }
        return res;
    }
};