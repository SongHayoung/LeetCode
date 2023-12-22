class Solution {
public:
    int maxScore(string s) {
        int z = 0, o = count(begin(s),end(s),'1');
        int res = 0;
        for(int i = 0; i < s.length() - 1; i++) {
            if(s[i] == '1') o -= 1;
            else z += 1;
            res = max(res, o + z);
        }
        return res;
    }
};