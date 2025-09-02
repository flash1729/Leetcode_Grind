class Solution {
public:
    struct maxP{
        bool operator()(vector<int> &p, vector<int> &q){
            double pOld = (double)p[0] / (double)p[1];
            double qOld = (double)q[0] / (double)q[1];

            double pNew = ((double)p[0] + 1) / ((double)p[1] + 1);
            double qNew = ((double)q[0] + 1) / ((double)q[1] + 1);

            return (pNew - pOld) < (qNew - qOld);
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<int>,vector<vector<int>>,maxP> pq;
        double average = 0;

        for(auto a : classes){
            pq.push(a);
            average += (double)a[0] / (double)a[1];
        }

        for(int i = 0; i < extraStudents; i++){
            vector<int> cur = pq.top();
            pq.pop();
            average -= (double)cur[0] / (double)cur[1];
            average += ((double)cur[0] + 1) / ((double)cur[1] + 1);
            pq.push({cur[0] + 1,cur[1] + 1});
        }

        return average / classes.size();
    }
};