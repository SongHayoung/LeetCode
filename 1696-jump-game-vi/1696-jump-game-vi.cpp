class Solution {
public:
    int maxResult(vector<int>& A, int k) {
        priority_queue<pair<int,int>> pq;
        pq.push({A[0],0});
        int res = A[0];
        for(int i = 1; i < A.size(); i++) {
            while(!pq.empty() and pq.top().second + k < i) pq.pop();
            res = pq.top().first + A[i];
            pq.push({res, i});
        }
        return res;
    }
};