class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        unordered_map<string,vector<string>> hashmap;

        for(int i = 0;i < strs.size();i++){
            string key = strs[i];
            sort(key.begin(),key.end());

            hashmap[key].push_back(strs[i]);
        }

        for(auto &pair : hashmap){
            result.push_back(pair.second);
        }

        return result;
    }
};