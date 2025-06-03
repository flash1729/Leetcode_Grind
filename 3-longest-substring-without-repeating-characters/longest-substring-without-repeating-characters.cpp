class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1); // Initialize with -1
        int maxLen = 0;
        int i = 0;

        for (int j = 0; j < s.length(); j++) {
            char temp = s[j];
            if (hash[temp] != -1 && hash[temp] >= i) {
                i = hash[temp] + 1;
            }
            hash[temp] = j;
            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};
