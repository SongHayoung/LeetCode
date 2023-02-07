class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        unordered_map<int, int> freq, cnt;
        for(auto p : prizePositions) freq[p] += 1;
        int ma = 0, res = 0, now = 0, l = prizePositions.size() - 1, r = l;
        while(l >= 0) {
            while(l > 0 and prizePositions[l] == prizePositions[l-1]) l -= 1;
            now += freq[prizePositions[l]];
            while(prizePositions[l] + k < prizePositions[r]) {
                while(r > 0 and prizePositions[r] == prizePositions[r-1]) r -= 1;
                now -= freq[prizePositions[r]];
                ma = max(ma, cnt[prizePositions[r]]);
                r -= 1;
            }
            cnt[prizePositions[l]] = now;
            res = max(res, now + ma);
            l -= 1;
        }
        return res;
    }
};