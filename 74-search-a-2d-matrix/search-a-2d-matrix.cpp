class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = m*n - 1;

        while(l <= r){
            
            int mid = l + (r-l)/2;

            if(target == matrix[mid/n][mid%n]){
                return true;
            }
            else if(target > matrix[mid/n][mid%n]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return false;
    }
};