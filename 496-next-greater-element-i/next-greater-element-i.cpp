class Solution {
public:
    int index(int n,vector<int> &n2){
        for(int i = 0;i < n2.size();i++){
            if(n2[i] == n){
                return i;
            }
        }

        return -1;
    }

    int greater(int ind, vector<int> n2){
        if(ind + 1 >= n2.size()){
            return -1;
        }

        for(int i = ind + 1;i < n2.size();i++){
            if(n2[i] > n2[ind]){
                return n2[i];
            }
        }

        return -1;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for(int i = 0;i < nums1.size();i++){
            int ind = index(nums1[i],nums2);

            ans.push_back(greater(ind,nums2));
        }

        return ans;
    }
};