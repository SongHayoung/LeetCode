class Solution {
public:
    int longestSquareStreak(vector<int>& A) {
        sort(begin(A), end(A));
        unordered_set<int> us(begin(A), end(A));
        int res = 0;
        for(int i = 0; i < A.size(); i++) {
            if(!us.count(A[i])) continue;
            long long now = A[i], cnt = 0;
            while(us.count(now)) {
                cnt += 1;
                us.erase(now);
                now = now * now;
            }
            res = max(res, (int)cnt);
        }
        return res == 1 ? -1 : res;
    }
};