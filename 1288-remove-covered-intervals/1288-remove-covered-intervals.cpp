class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& A) {
        int res = 0;
        sort(begin(A), end(A), [](auto a, auto b) {
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        auto cover = [&](int i, int j) {
            return A[i][0] <= A[j][0] and A[j][1] <= A[i][1];
        };
        for(int i = 0; i < A.size();) {
            res++;
            int j = i + 1;
            while(j < A.size() and cover(i,j)) j++;
            i = j;
        }
        return res;
    }
};