// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         // what i am thinking is we will keep track of flipping and that array will contain places where 0 is flipped to 1 and when we can no longer flip then we will bring i to least index + 1 (remove the flipped from array and make it one again)where 0 was flipped maybe 
// // youll ask why cause maybe after that we will get possiblity to flip next 0s i think this is the key
//     }
// };

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int maxLength = 0;
        queue<int> zeroPositions; // Track positions of zeros we've "flipped"
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                zeroPositions.push(right);
            }
            
            // If we have more than k zeros, remove the leftmost one
            if (zeroPositions.size() > k) {
                left = zeroPositions.front() + 1; // Jump directly!
                zeroPositions.pop();
            }
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};