class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long MOD = 1e9 + 7;
        int n = arr.size();
        
        // Stack stores indices of elements in increasing order of value
        stack<int> st; 
        
        // dp[i] = sum of minimums for subarrays ending at index i-1
        vector<long> dp(n + 1, 0);
        long totalSum = 0;

        for (int i = 0; i < n; ++i) {
            // Find previous less element
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            int ple_idx = st.empty() ? -1 : st.top();
            
            // Calculate dp[i+1] using the recurrence
            // dp[ple_idx + 1] handles the sum for subarrays starting before the PLE
            // (i - ple_idx) * arr[i] is the sum for subarrays where arr[i] is the new minimum
            dp[i + 1] = (dp[ple_idx + 1] + (long)(i - ple_idx) * arr[i]) % MOD;

            st.push(i);
            
            // Add current dp value to the total sum
            totalSum = (totalSum + dp[i + 1]) % MOD;
        }

        return totalSum;
    }
};