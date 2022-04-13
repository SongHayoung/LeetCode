class Solution {
    int helper(string& s, int& i, int d = 0) {
        int score = 0;
        int st = 0;
        while(i < s.length()) {
            if(s[i] == '(') {
                if(st == 0) {
                    st++;
                } else {
                    score += 2*helper(s,i,d+1);
                }
            } else {
                st--;
                if(st == 0) {                    
                    return score ? score : 1;
                } else {
                    score += 1;
                }
            }
            i++;
        }
        return score;
    }
public:
    int scoreOfParentheses(string S) {
        int i = 0;
        int res = 0;
        while(i < S.length()) {
            res += helper(S,i);
            i++;
        }
        return res;
    }
};