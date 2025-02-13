class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0;
        int ops = 0;
        priority_queue<double> res;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            res.push(nums[i]);
        }
        double temp = sum;
        cout<<"temp = "<<temp<<endl;

        while(sum > temp / 2){
            ops++;
            double popEle = res.top();
            res.pop();
            sum -= popEle;
            popEle /= 2;
            res.push(popEle);
            sum += popEle;
        }

        return ops;
    }
};