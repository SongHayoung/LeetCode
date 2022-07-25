class Solution {
    pair<string, int> AB(string& s, int p) {
        string ss = "";
        int res = 0;
        for(auto& ch : s) {
            if(ch == 'b' and !ss.empty() and ss.back() == 'a') {
                ss.pop_back();
                res += p;
            } else ss.push_back(ch);
        }
        return {ss,res};
    }
    pair<string, int> BA(string& s, int p) {
        string ss = "";
        int res = 0;
        for(auto& ch : s) {
            if(ch == 'a' and !ss.empty() and ss.back() == 'b') {
                ss.pop_back();
                res += p;
            } else ss.push_back(ch);
        }
        return {ss,res};
    }
public:
    int maximumGain(string s, int x, int y) {
        if(x > y) {
            auto [ss, res1] = AB(s,x);
            auto [_,res2] = BA(ss,y);
            return res1 + res2;
        }
        auto [ss, res1] = BA(s,y);
        auto [_, res2] = AB(ss,x);
        return res1 + res2;
    }
};