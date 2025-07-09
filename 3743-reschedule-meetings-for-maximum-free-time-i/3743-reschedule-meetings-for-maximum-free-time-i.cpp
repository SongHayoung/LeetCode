class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& S, vector<int>& E) {
        int res = 0, sum = 0;
        for(int i = 0; i < S.size(); i++) {
            sum += E[i] - S[i];
            if(i >= k) sum -= E[i-k] - S[i-k];
            int st = i >= k ? E[i-k] : 0;
            int ed = i + 1 == S.size() ? eventTime : S[i+1];
            res = max(res, ed - st - sum);
        }
        return res;
    }
};