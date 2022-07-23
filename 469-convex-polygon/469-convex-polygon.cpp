class Solution {
    long long det(vector<int>& A, vector<int>& B, vector<int>& C) {
        return 1ll * (B[0] - A[0]) * (C[1] - A[1]) - 1ll * (B[1] - A[1]) * (C[0] - A[0]);
    }
public:
    bool isConvex(vector<vector<int>>& points) {
        long long last = 0, n = points.size();
        for(int i = 0; i < n; i++) {
            long long now = det(points[i], points[(i+1)%n], points[(i+2)%n]);
            if(now) {
                if(now * last < 0) return false;
                last = now;
            }
        }
        return true;
    }
};