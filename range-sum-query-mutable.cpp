class NumArray {
    vector<int> acc;
    vector<int> nums;
    map<int, int> updated;
    void updateAcc(int from) {
        for(int i = from; i < nums.size(); i++) {
            acc[i + 1] = acc[i] + nums[i];
        }
    }
    void updateNums() {
        int minimumUpdate = updated.lower_bound(-1)->first;
        for(auto& entity : updated) {
            nums[entity.first] = entity.second;
        }
        updateAcc(minimumUpdate);
        updated.clear();
    }
public:
    NumArray(vector<int>& nums) : nums(nums){
        acc.reserve(nums.size() + 1);
        acc[0] = 0;
        updateAcc(0);
    }

    void update(int index, int val) {
        updated[index] = val;
        if(updated.size() >= 100) {
            updateNums();
        }
    }

    int sumRange(int left, int right) {
        int res = acc[right + 1] - acc[left];
        for(auto it = updated.lower_bound(left); it != end(updated) && it->first <= right; it++) {
            res = res - nums[it->first] + updated[it->first];
        }
        return res;
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
