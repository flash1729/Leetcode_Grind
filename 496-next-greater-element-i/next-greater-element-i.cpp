class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        stack<int> ind;
        int n2 = nums2.size();
        unordered_map<int,int> ng;


        for(int i = n2 - 1 ; i >= 0; i--){
            while(!ind.empty() && nums2[ind.top()] <= nums2[i]){
                ind.pop();
            }

            if(ind.empty()){
                ng[nums2[i]] = -1;
            }else{
                ng[nums2[i]] = nums2[ind.top()];
            }

            ind.push(i);
        }

        for(int i = 0;i < nums1.size();i++){
            res.push_back(ng[nums1[i]]);
        }

        return res;
    }
};