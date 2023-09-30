class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> has(k+1);
        int res = 0;
        while(nums.size()) {
            int x = nums.back(); nums.pop_back();
            if(1 <= x and x <= k) has[x] = 1;
            bool ok = true;
            for(int i = 1; i <= k; i++) ok &= has[i];
            res += 1;
            if(ok) return res;
        }
        return -1;
    }
};