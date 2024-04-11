class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        for(auto& ch : num) {
            while(!res.empty() and k and res.back() > ch) {
                res.pop_back();
                k--;
            }
            res.push_back(ch);
        }
        while(k and !res.empty()) {
            res.pop_back();
            k--;
        }
        int cut = 0;
        for(; cut < res.length() and res[cut] == '0'; cut++) {}
        res = res.substr(cut);
        return res.length() ? res : "0";
    }
};
