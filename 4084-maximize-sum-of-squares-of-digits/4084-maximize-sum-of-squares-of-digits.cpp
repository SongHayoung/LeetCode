class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num * 9 < sum) return "";
        string res = "";
        for(int i = 0; i < num; i++) {
            int now = min(sum, 9);
            res.push_back(now + '0');
            sum -= now;
        }
        return res;
    }
};