class Solution {
    vector<int> fenwickTree;
    int append = 10001;
    void update(int idx, int v) {
        while(idx < fenwickTree.size()) {
            fenwickTree[idx] += v;
            idx = idx + (idx & -idx);
        }
    }
    int sum(int idx) {
        int res = 0;
        while(idx > 0) {
            res += fenwickTree[idx];
            idx = idx - (idx & -idx);
        }
        return res;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        fenwickTree = vector<int>(20003, 0);
        vector<int> res(nums.size(), 0);
        for(int i = 1; i < nums.size(); i++) {
            update(nums[i] + append,1);
        }
        
        for(int i = 0; i < nums.size() - 1; i++) {
            res[i] = sum(nums[i] + append-1);
            update(nums[i+1] + append, -1);
        }
        return res;
    }
};