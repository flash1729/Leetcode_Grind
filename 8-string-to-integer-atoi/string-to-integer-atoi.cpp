class Solution {
public:
    int myAtoi(string s) {
        bool started = false;
        bool pos = true;
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' && started == false)
                continue;
            else if ((s[i] == '-' || s[i] == '+') && started == false) {
                if (s[i] == '-') {
                    pos = false;
                }
                started = true;
            } else if (s[i] <= '9' && s[i] >= '0') {
                started = true;
                if(static_cast<long long>(static_cast<long long>(ans * 10) + (s[i] - '0')) >
                    pow(2,31) - 1) {
                    return pos == true ? 2147483647
 : -2147483648;
                } else {
                    ans = ans * 10 + (s[i] - '0');
                }
            } else {
                return pos == true ? static_cast<int>(ans) : static_cast<int>(-1 * ans);

                break;
            }
        }
        return pos == true ? static_cast<int>(ans) : static_cast<int>(-1 * ans);
    }
};