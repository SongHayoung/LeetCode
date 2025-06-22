class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        string now = "";
        vector<string> res;
        for(auto& ch : s) {
            now.push_back(ch);
            if(now.size() == k) {
                res.push_back(now);
                now = "";
            }
        }
        if(now != "") {
            while(now.size() < k) now.push_back(fill);
            res.push_back(now);
        }
        return res;
    }
};