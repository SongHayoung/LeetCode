class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string res = "a", all = "";
        for(auto s : strs) {
            string rev = s;
            reverse(begin(rev),end(rev));
            all += max(rev,s);
        }
        for(int i = 0, cut = 0; i < strs.size(); cut += strs[i].length(), i++) {
            string now = strs[i], rev = strs[i], rest = all.substr(cut + strs[i].length()) + all.substr(0, cut);
            reverse(begin(rev),end(rev));
            for(int j = 0; j < now.length(); j++) {
                res = max(res, now.substr(j) + rest + now.substr(0,j));
                res = max(res, rev.substr(j) + rest + rev.substr(0,j));
            }
        }
        return res;
    }
};