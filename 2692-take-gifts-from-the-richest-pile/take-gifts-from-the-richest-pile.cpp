class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for (int i = 0; i < gifts.size(); i++) {
            pq.push(gifts[i]);
        }
        
        long long temp;

        for (int i = 0; i < k; i++) {
            temp = pq.top();
            pq.pop();
            pq.push(static_cast<long long>(floor(sqrt(temp))));
        }

        temp = 0;

        while (!pq.empty()) {
            temp += pq.top();
            pq.pop();
        }

        return temp;
    }
};