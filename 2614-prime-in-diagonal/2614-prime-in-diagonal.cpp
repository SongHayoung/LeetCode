class Solution {
    bool prime(int k) {
        if(k == 1) return false;
        for(int i = 2; i * i <= k; i++) {
            if(k % i) continue;
            return false;
        }
        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size(), res = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(nums[i][j] <= res) continue;
            if(i == j or (n - i - 1 == j)) {
                if(prime(nums[i][j])) res = nums[i][j];
            }
        }
        return res;
    }
};