class Solution {
public:
    int minimumChairs(string s) {
        int res = 0, now = 0;
        for(auto& ch : s) {
            if(ch == 'E') now++;
            else now--;
            res = max(res, now);
        }
        return res;
    }
};