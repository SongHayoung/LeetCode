class Solution {
    unordered_map<string, string> dp;
    int repCount(string& s, int st, string& rep) {
        int res = 1;

        for(int i = st + rep.length(); i + rep.length() <= s.length(); i += rep.length()) {

            for(int j = i; j < i + rep.length(); j++) {
                if(rep[j-i] != s[j]) return res;
            }
            res++;
        }
        return res;
    }
    string solution(string s) {
        if(s.length() < 5) return s;
        if(dp.count(s)) return dp[s];
        string res = s;
        string rep = "";

        for(int i = 0; i < s.length(); i++) {
            rep += s[i];
            int cnt = repCount(s,0,rep);
            string str;

            for(int j = 1; j <= cnt; j++) {
                if(j == 1) str = rep + solution(s.substr(j*(i+1)));
                else str = to_string(j) + '[' + solution(rep) + ']' + solution(s.substr((i+1)*j));
                if(str.length() < res.length()) res = str;
            }
        }

        return dp[s] = res;
    }
public:
    string encode(string s) {
        return solution(s);
    }
};