class ProductOfNumbers {
public:
    vector<int> nums;
    ProductOfNumbers() { }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        long long res = 1;
        for(int i = 0;i < k;i++){
            // cout<<nums[nums.size() - 1 - i] << "   " << res<<endl;
            res *= nums[nums.size() - 1 - i];
        }

        // cout<<(int)res<<endl;
        return (unsigned int)res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */