class NumArray {
    vector<int> fenwick;
    vector<int> numbers;
    void up(int index, int val) {
        while(index < fenwick.size()) {
            fenwick[index] += val;
            index += index & -index;
        }
    }
    int sum(int index) {
        int res = 0;
        while(index > 0) {
            res += fenwick[index];
            index -= index & -index;
        }
        return res;
    }
public:
    NumArray(vector<int>& nums) {
        numbers = nums;
        fenwick = vector<int>(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++) {
            up(i + 1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        if(numbers[index] == val) return;
        int diff = val - numbers[index];
        up(index + 1, diff);
        numbers[index] = val;
    }
    
    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */