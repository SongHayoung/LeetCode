class Solution {
    int dfs(vector<int>& prefixSum, int num) {
        if(num <= 1) return num ? 2 : 1;
        for(int i = 31; i >= 0; i--) {
            if(num & (1<<i)) {
                return prefixSum[i-1] + (num & 1<<(i-1) ? dfs(prefixSum, (1<<(i-1))-1) : dfs(prefixSum, (num ^ (1<<i))));
            }
        }
        return -1;
    }
public:
    int findIntegers(int n) {
        if(n <= 1) return n ? 2 : 1;
        vector<int> dp{2, 1}, prefixSum{2,3};
        for(int i = 2; i < 31; i++) {
            dp.push_back(prefixSum[i-2]);
            prefixSum.push_back(prefixSum.back() + dp.back());
        }

        return dfs(prefixSum, n);
    }
};