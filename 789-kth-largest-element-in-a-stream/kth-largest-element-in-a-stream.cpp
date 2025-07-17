class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int lim = 1;
    void setLim(int k){
        lim = k;
    }

    KthLargest(int k, vector<int>& nums) {
        setLim(k);

        for(int a : nums){
            pq.push(a);

            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        if(pq.size() < lim){
            pq.push(val);

            return pq.size() >= lim ? pq.top() : 0;
        }else{
            if(val > pq.top()){
                pq.pop();
                pq.push(val);
            }
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */