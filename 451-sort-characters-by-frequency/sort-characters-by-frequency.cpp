class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char a : s) {
            freq[a]++;
        }
        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second;
    };
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);


        for (const auto& [key, value] : freq) {
            pq.push({key, value});
        }
        string result;
    while (!pq.empty()) {
        auto [ch, freq] = pq.top();
        pq.pop();
        result.append(freq, ch); // Append 'ch' 'freq' times
    }

    return result;
    }
};