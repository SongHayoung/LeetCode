class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string res = countAndSay(n - 1);
        stringstream ss;
        int cnt = 1;
        for(int i = 0; i < res.length() - 1; i++) {
            if(res[i] == res[i + 1]) cnt++;
            else {
                ss << to_string(cnt) << res[i];
                cnt = 1;
            }
        }
        return ss.str() + to_string(cnt) + res.back();
    }
};
