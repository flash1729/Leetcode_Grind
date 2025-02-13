// class Solution {
// public:
//     int halveArray(vector<int>& nums) {
//         double sum = 0;
//         int ops = 0;
//         priority_queue<double> res;
//         for(int i = 0;i < nums.size();i++){
//             sum += nums[i];
//             res.push(nums[i]);
//         }
//         double temp = sum;
//         cout<<"temp = "<<temp<<endl;

//         while(sum > temp / 2){
//             ops++;
//             double popEle = res.top();
//             res.pop();
//             sum -= popEle / 2;
//             popEle /= 2;
//             res.push(popEle);
//         }

//         return ops;
//     }
// };

class Solution {
public:
    int halveArray(vector<int>& nums) {
        int ops {0};
        double sum {0};
        for(int num : nums) { sum += num; }
        double half_sum = (double)sum / 2;
        priority_queue<double> pq(nums.begin(), nums.end());
        while(sum > half_sum) {
            double num = pq.top(); pq.pop();
            sum -= num;
            double half = num / 2;
            sum += half;
            pq.push(half);
            ++ops;
        }
        return ops;
    }
};