class Solution {
public:
    int findSpecialInteger(vector<int>& A) {
        int n = A.size(), now = -1, cnt = 0;
        for(auto& x : A) {
            if(x == now) cnt += 1;
            else cnt = 1, now = x;
            if(cnt * 4 > n) return x;
        }
        return 0;
    }
};