class Solution {
public:
    int minimumAddedCoins(vector<int>& A, int t) {
        sort(rbegin(A), rend(A));
        int now = 1, res = 0;
        while(now <= t) {
            if(A.size() and A.back() <= now) {
                now += A.back(); A.pop_back();
            } else {
                res += 1;
                now += now;
            }
        }
        
        return res;
    }
};