class Solution {
public:
    int minConnectedGroups(vector<vector<int>>& intervals, int k) {
        vector<vector<int>> A;
        sort(begin(intervals), end(intervals));
        for(auto& i : intervals) {
            if(A.size() == 0 or A.back()[1] < i[0]) A.push_back(i);
            else A.back()[1] = max(A.back()[1], i[1]);
        }
        int n = A.size(), res = n;
        for(int i = 0, j = 0; i < n; i++) {
            while(j < n and A[j][0] <= A[i][1] + k) j++;
            res = min(res, i + 1 + n - j);
        }
        return res;
    }
};