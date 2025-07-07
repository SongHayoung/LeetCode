class Solution {
public:
    int maxEvents(vector<vector<int>>& A) {
        priority_queue<int,vector<int>,greater<int>> q;
        sort(rbegin(A), rend(A));
        int d = A.back()[0], res = 0;
        while(A.size()) {
            while(q.size() and q.top() < d) q.pop();
            while(A.size() and A.back()[0] <= d) {
                q.push(A.back()[1]); A.pop_back();
            }
            if(q.size()) {
                q.pop();
                res++;
                d++;
            } else {
                if(A.size()) d = A.back()[0];
            }
        }
        while(q.size()) {
            while(q.size() and q.top() < d) q.pop();
            if(q.size()) {
                q.pop();
                res++;
                d++;
            }
        }
        return res;
    }
};