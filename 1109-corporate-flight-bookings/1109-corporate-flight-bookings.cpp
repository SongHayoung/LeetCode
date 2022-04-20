class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> A(n + 1), res(n);
        for(auto& b : bookings) {
            A[b[0] - 1] += b[2];
            A[b[1]] -= b[2];
        }
        for(int i = 0; i < n; i++) {
            res[i] = A[i] + (i - 1 < 0 ? 0 :res[i - 1]);
        }
        return res;
    }
};