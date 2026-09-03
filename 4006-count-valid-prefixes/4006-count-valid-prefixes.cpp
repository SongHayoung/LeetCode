class Solution {
public:
    int countValidPrefixes(string s) {
        int res = 0, sum = 0;
        for(auto& ch : s) {
            sum += (ch == '0' ? -1 : 1);
            if(abs(sum) <= 1) res++;
        }
        return res;
    }
};