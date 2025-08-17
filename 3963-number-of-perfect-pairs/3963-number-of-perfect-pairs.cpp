
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        long long n = nums.size(), res = 0;
        vector<long long> A;
        for(auto& n : nums) A.push_back(abs(n));
        sort(begin(A), end(A));
        
        for(int i = 0, j = 1; i < n; i++) {
            j = max(j, i + 1);
            while(j < n and A[j] <= 2 * A[i]) j++;
            res += (j - i - 1);
        }
        return res;
    }
};