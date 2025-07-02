#include <vector>
#include <stack>

class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        const int MOD = 1e9 + 7;
        
        // Stack stores indices of elements, maintaining a non-decreasing value sequence.
        std::stack<int> st;

        // Loop through i from 0 to n. i=n acts as a sentinel to pop all remaining elements.
        for (int i = 0; i <= n; ++i) {
            // When i=n, current_val is 0. Since 1 <= arr[i], this is a sentinel
            // that is smaller than any element, ensuring the stack is emptied.
            int current_val = (i == n) ? 0 : arr[i];
            
            // Pop elements from stack that are >= current_val.
            // For a popped element arr[j], current_val is its Next Less-or-Equal Element (NLE).
            // The element below it on the stack is its Previous Less Element (PLE).
            while (!st.empty() && arr[st.top()] >= current_val) {
                int j = st.top(); // Index of the element being calculated
                st.pop();
                
                int k = st.empty() ? -1 : st.top(); // Index of PLE
                
                // Distance to PLE: (j - k)
                // Distance to NLE: (i - j)
                long long count = (long long)(j - k) * (i - j);
                
                // Contribution of arr[j] to the total sum
                long long contribution = (count * arr[j]);
                ans = (ans + contribution) % MOD;
            }
            
            st.push(i);
        }
        
        return ans;
    }
};