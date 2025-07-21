class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char,int> freq;
        freq['T'] = 0;
        freq['F'] = 0;

        int i = 0;
        int least = 0;
        int ans = 0;

        for(int j = 0; j < answerKey.size();j++){
            freq[answerKey[j]]++;

            while(min(freq['T'],freq['F']) > k){
                freq[answerKey[i]]--;
                i++;
            }

            ans = max(ans,j - i + 1);
        }

        return ans;
    }
};