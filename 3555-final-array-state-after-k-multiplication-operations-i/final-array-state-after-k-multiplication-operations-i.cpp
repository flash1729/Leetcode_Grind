class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;

        for (int i = 0; i < n; i++) {
            q.push(make_pair(nums[i],i));
        }

        for (int i = 0; i < k; i++) {
            int temp = q.top().first;
            int index = q.top().second;

            q.pop();
            temp = temp * multiplier;
            q.push(make_pair(temp,index));
            nums[index] = temp;
        }

        return nums;
    }
};