class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        vector<int> sum(A.size() * 2, 0);
        int res = INT_MIN, sz = A.size();
        pair<int, int> minP{0, 0}, maxP{0, 0};
        priority_queue<pair<int, int>> minPQ;
        minPQ.push({0, 0});
        for(int i = 0; i < sz; i++) {
            sum[i + 1] = sum[i] + A[i];
            minPQ.push({-sum[i + 1], i + 1});
            if(sum[i + 1] >= maxP.first) {
                res = max(res, sum[i + 1] - minP.first);
                maxP.first = sum[i + 1];
                maxP.second = i;
            } else if(sum[i + 1] <= minP.first) {
                res = max(res, sum[i + 1] - minP.first);
                minP = maxP = {sum[i + 1], i};
            }
        }

        for(int i = 0; i < sz - 1; i++) {
            sum[i + sz + 1] = sum[i + sz] + A[i];
            minPQ.push({-sum[i + 1 + sz], i + sz + 1});
            if(sum[i + 1 + sz] >= maxP.first) {
                if(minP.second <= i + 1) {
                    while(!minPQ.empty() && minP.second <= i + 1) {
                        minP = minPQ.top();
                        minPQ.pop();
                    }
                    minP.first *= -1;
                }
                res = max(res, sum[i + 1 + sz] - minP.first);
                maxP.first = sum[i + 1 + sz];
                maxP.second = i + sz;
            } else if(sum[i + 1 + sz] <= minP.first) {
                if(minP.second <= i + 1) {
                    while(!minPQ.empty() && minP.second <= i + 1) {
                        minP = minPQ.top();
                        minPQ.pop();
                    }
                    minP.first *= -1;
                }
                res = max(res, sum[i + 1 + sz] - minP.first);
                minP = maxP = {sum[i + 1 + sz], i + sz};
            }
        }

        return res;
    }
};
