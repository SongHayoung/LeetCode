class Solution {
public:
    int minOperations(vector<int>& A, vector<int>& B) {
        int g = B[0];
        for(auto& b : B)
            g = __gcd(g,b);
        sort(begin(A), end(A));
        for(int i = 0; i < A.size(); i++) {
            if(A[i] > g) break;
            if(g % A[i] == 0) return i;
        }
        return -1;
    }
};