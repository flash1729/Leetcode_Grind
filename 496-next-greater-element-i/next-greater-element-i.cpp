class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> myStack;
        unordered_map<int,int> ng;
        vector<int> ans;
        for(int i = 0;i < nums2.size();i++){
            while(!myStack.empty()){
                if(myStack.top() < nums2[i]){
                    ng[myStack.top()] = nums2[i];
                    myStack.pop();
                }
                else{
                    break;
                }
            }
            myStack.push(nums2[i]);
        }
        while(!myStack.empty()){
            ng[myStack.top()] = -1;
            myStack.pop();
        }

        for(int i : nums1){
            ans.push_back(ng[i]);
        }

        return ans;
    }
};