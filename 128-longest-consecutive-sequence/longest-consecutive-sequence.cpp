#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_map<int, int> lengths; // stores length of sequence ending at this number
        unordered_map<int, bool> processed; // to avoid reprocessing
        
        for (int num : nums) {
            if (processed[num]) continue; // skip duplicates
            
            processed[num] = true;
            
            // Check if we can extend existing sequences
            int leftLength = 0, rightLength = 0;
            
            // Check if there's a sequence ending at num-1
            if (lengths.count(num - 1)) {
                leftLength = lengths[num - 1];
            }
            
            // Check if there's a sequence starting at num+1
            if (lengths.count(num + 1)) {
                rightLength = lengths[num + 1];
            }
            
            // Current sequence length
            int currentLength = 1 + leftLength + rightLength;
            
            // Update the endpoints of the new merged sequence
            lengths[num - leftLength] = currentLength;  // leftmost end
            lengths[num + rightLength] = currentLength; // rightmost end
            
            // Also update current position (helpful for debugging)
            lengths[num] = currentLength;
        }
        
        int maxLength = 0;
        for (auto& p : lengths) {
            maxLength = max(maxLength, p.second);
        }
        
        return maxLength;
    }
};