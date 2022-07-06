class Solution {
public:
    int widestPairOfIndices(vector<int>& A, vector<int>& B) {
        int res = 0, n = A.size();
        unordered_map<int, int> mp;
        mp[0] = {-1};
        for(int i = 0, sum = 0; i < n; i++) {
            sum += A[i] - B[i];
            if(mp.count(sum)) res = max(res, i - mp[sum]);
            else mp[sum] = i;
        }
        return res;
    }
};