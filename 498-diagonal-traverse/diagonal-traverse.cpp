class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int r = mat.size();
        int c = mat[0].size();

        q.push({0,0});
        vector<int> res;
        bool flag = true;
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        visited[0][0] = true;

        while(!q.empty()){
            int itr = q.size();
            vector<int> level(itr);
            flag = (flag == true) ? false : true;
            // cout<<itr<<endl;

            for(int a = 0;a < itr; a++){
                pair<int,int> cur = q.front();
                q.pop();

                int i = cur.first;
                int j = cur.second;

                if(j+1 < c && i < r && !visited[i][j+1]){
                    q.push({i,j+1});
                    visited[i][j+1] = true;
                    // cout<<i<<" "<<j+1<<" "<<mat[i][j+1]<<endl;
                }

                if(i+1 < r && j < c && !visited[i+1][j]){
                    q.push({i+1,j});
                    visited[i+1][j] = true;
                    // cout<<i+1<<" "<<j<<" "<<mat[i+1][j]<<endl;
                }

                if(flag == true){
                    level[a] = mat[cur.first][cur.second];
                }else{
                    level[itr - a - 1] = mat[cur.first][cur.second];
                }
            }

            for(int i = 0;i < itr;i++){
                res.push_back(level[i]);
                // cout<<level[i]<<" ";
            }
        }

        return res;
    }
};