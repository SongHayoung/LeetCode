class Solution {
public:
    int minGroups(vector<vector<int>>& A) {
        sort(begin(A), end(A));
        priority_queue<int, vector<int>, greater<int>> q;
        int res = 0;
        for(int i = 0; i < A.size(); i++){
            int s = A[i][0], e = A[i][1];
            while(!q.empty() and q.top() < s) q.pop();
            q.push(e);
            res = max(res, (int)q.size());
        }
        return res;
    }
};
