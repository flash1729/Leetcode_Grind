class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        // 1. Calculate total sum
        long long totalSum = 0;
        for (int point : cardPoints) {
            totalSum += point;
        }

        // 2. Handle edge case where you take all cards
        if (k == n) {
            return totalSum;
        }

        // 3. Find the sum of the initial window to be removed
        int window_size = n - k;
        long long current_window_sum = 0;
        for (int i = 0; i < window_size; i++) {
            current_window_sum += cardPoints[i];
        }
        
        long long min_sum_to_remove = current_window_sum;

        // 4. Slide the window to find the minimum possible sum to remove
        for (int j = window_size; j < n; j++) {
            // Update sum in O(1) by adding new element and removing old one
            current_window_sum += cardPoints[j] - cardPoints[j - window_size];
            min_sum_to_remove = min(min_sum_to_remove, current_window_sum);
        }

        // 5. The result is the total minus the smallest sum we could leave behind
        return totalSum - min_sum_to_remove;
    }
};