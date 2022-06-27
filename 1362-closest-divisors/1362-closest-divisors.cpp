class Solution {
    vector<int> helper(int n) {
        int s = sqrt(n);
        while(s) {
            if(n % s == 0) return {s, n/s};
            s--;
        }
        return {};
    }
public:
    vector<int> closestDivisors(int num) {
        vector<int> A = helper(num + 1), B = helper(num + 2);
        return abs(A[0] - A[1]) < abs(B[0] - B[1]) ? A : B;
    }
};