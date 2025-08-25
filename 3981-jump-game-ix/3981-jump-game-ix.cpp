class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size(), ma = -1;
        vector<int> res(n, -1), suf(n);
        for(int i = n - 1; i >= 0; i--) {
            suf[i] = nums[i];
            if(i + 1 < n) suf[i] = min(suf[i], suf[i+1]);
        }
        for(int i = 0; i < n; i++) {
            ma = max(ma, nums[i]);
            if(i + 1 == n or suf[i+1] >= ma) {
                int j = i;
                while(j >= 0 and res[j] == -1) res[j--] = ma;
            }
        }
        return res;
    }
};