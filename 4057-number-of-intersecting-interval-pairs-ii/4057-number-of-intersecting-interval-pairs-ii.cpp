class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& A) {
        sort(begin(A), end(A));
        long long res = 0;
        priority_queue<int,vector<int>,greater<>> q;
        for(auto& interval : A) {
            int s = interval[0], e = interval[1];
            while(q.size() and q.top() < s) q.pop();
            res += q.size();
            q.push(e);
        }
        return res;
    }
};