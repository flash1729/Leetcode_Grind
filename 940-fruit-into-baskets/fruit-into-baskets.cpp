class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int res = 0;
        unordered_map<int,int> freq;

        for(int j = 0;j < fruits.size();j++){
            int right_fruit = fruits[j];

            freq[right_fruit]++;

            while(freq.size() > 2){
                int left_fruit = fruits[i];
                freq[left_fruit] -= 1;

                if(freq[left_fruit] == 0){
                    freq.erase(left_fruit);
                }
                i++;
            }

            res = max(res,j - i + 1);
        }

        return res;
    }
};