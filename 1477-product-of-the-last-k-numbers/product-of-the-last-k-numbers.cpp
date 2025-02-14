class ProductOfNumbers {
public:
    vector<int> nums;
    ProductOfNumbers() {
        nums.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            nums.clear();
            nums.push_back(1);
        }
        else{
            nums.push_back(num*nums[nums.size() - 1]);
        }
    }
    
    int getProduct(int k) {
        if(k > nums.size() - 1) return 0;
        return nums[nums.size() - 1] / nums[nums.size() - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */