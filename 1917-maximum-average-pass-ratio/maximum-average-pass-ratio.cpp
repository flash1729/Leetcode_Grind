class Solution {
public:
    struct MaxImprovement {
        bool operator()(const vector<int>& p, const vector<int>& q) {
            // Calculate improvement for each class
            double pImprovement = ((double)(p[0] + 1) / (p[1] + 1)) - ((double)p[0] / p[1]);
            double qImprovement = ((double)(q[0] + 1) / (q[1] + 1)) - ((double)q[0] / q[1]);
            
            // Max heap: return true if p has less improvement than q
            return pImprovement < qImprovement;
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<int>, vector<vector<int>>, MaxImprovement> pq;
        
        // Add all classes to priority queue
        for(const auto& cls : classes) {
            pq.push(cls);
        }
        
        // Distribute extra students
        for(int i = 0; i < extraStudents; i++) {
            vector<int> bestClass = pq.top();
            pq.pop();
            
            // Add one student to this class
            bestClass[0]++; // passing students
            bestClass[1]++; // total students
            
            pq.push(bestClass);
        }
        
        // Calculate final average
        double totalRatio = 0;
        while(!pq.empty()) {
            vector<int> cls = pq.top();
            pq.pop();
            totalRatio += (double)cls[0] / cls[1];
        }
        
        return totalRatio / classes.size();
    }
};