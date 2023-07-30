class Solution {
public:
    int missingNumber(vector<int>& A) {
        sort(begin(A), end(A));
        unordered_map<int, int> best{{0,0}};
        for(int i = 0; i < A.size() - 1; i++) {
            best[A[i+1]-A[i]] += 1;
        }
        int diff = 0;
        for(auto [k,v] : best) {
            if(v > best[diff]) diff = k;
        }
        for(int i = 0; i < A.size() - 1; i++) {
            if(A[i+1] - A[i] != diff) return A[i] + diff;
        }
        return A[0] + diff;
    }
};