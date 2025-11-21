class Solution {
public:
    int makeArrayPositive(vector<int>& A) {
        int res = 0, n = A.size(), i = 0;
        while(i + 2 < n) {
            vector<long long> pre{0};
            long long best = 0;
            while(i < n) {
                pre.push_back(pre.back() + A[i++]);
                if(pre.size() >= 4) {
                    best = max(best, pre[pre.size() - 4]);
                    if(pre.back() - best <= 0) {
                        res++;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
