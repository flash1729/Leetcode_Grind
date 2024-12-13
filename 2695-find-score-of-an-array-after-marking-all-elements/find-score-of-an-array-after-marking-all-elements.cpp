#include <vector>
#include <queue>
#include <climits>

class Solution {
public:
    long long findScore(std::vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        
        // Min-heap to store values along with their indices
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

        // Push all elements with their indices into the heap
        for (int i = 0; i < n; ++i) {
            pq.emplace(nums[i], i);
        }

        // Boolean vector to mark elements as processed
        std::vector<bool> processed(n, false);

        while (!pq.empty()) {
            auto [value, index] = pq.top();
            pq.pop();

            // If the element is already processed, skip it
            if (processed[index]) {
                continue;
            }

            // Add value to the score
            score += value;

            // Mark the current and adjacent elements as processed
            processed[index] = true;
            if (index - 1 >= 0) {
                processed[index - 1] = true;
            }
            if (index + 1 < n) {
                processed[index + 1] = true;
            }
        }

        return score;
    }
};
