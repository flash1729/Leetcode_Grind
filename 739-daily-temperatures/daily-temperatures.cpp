class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> index;
        vector<int> result(temperatures.size(), 0);

        for(int i = 0;i < temperatures.size();i++){
            while(!index.empty()){
                if(temperatures[index.top()] < temperatures[i]){
                    result[index.top()] = i - index.top();
                    index.pop();
                }else{
                    break;
                }
            }

            index.push(i);
        }

        return result;
    }
};