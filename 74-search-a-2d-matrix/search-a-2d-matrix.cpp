class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = m - 1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(target == matrix[mid][0]){
                return true;
            }
            else if(target > matrix[mid][0] && mid + 1 <= m - 1){
                l = mid + 1;
            }
            else if(target < matrix[mid][0] && mid - 1 >= 0){
                r = mid - 1;
            }else{
                break;
            }
        }

        int al = 0;
        int ar = n - 1;
        cout<<l<<" "<<r<<endl;

        while(al <= ar){
            int mid = al + (ar-al)/2;

            if(target == matrix[r][mid]){
                return true;
            }   
            else if(target > matrix[r][mid] && mid + 1 <= n - 1){
                al = mid + 1;
            }
            else if(mid - 1 >= 0){
                ar = mid - 1;
            }
            else{
                break;
            }
        }

        return false;
    }
};