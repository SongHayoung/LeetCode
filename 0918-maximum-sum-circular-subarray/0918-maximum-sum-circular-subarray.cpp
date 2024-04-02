class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        deque<pair<int, int>> dq;
        int res = INT_MIN;
        dq.push_back({-1,0});
        for(int i = 0, pre = 0; i < A.size() * 2; i++) {
            pre += A[i%A.size()];
            while(dq.size() and dq.back().second >= pre) {
                res = max(res, pre - dq.back().second);
                dq.pop_back();
            }
            if(dq.size() and i - dq.front().first == A.size() + 1) dq.pop_front();
            if(dq.size()) res = max(res, pre - dq.front().second);
            dq.push_back({i,pre});
        }
        return res;
    }
};