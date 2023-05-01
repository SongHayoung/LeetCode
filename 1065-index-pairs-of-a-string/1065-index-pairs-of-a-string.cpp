class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> res;
        for(auto w : words) {
            if(w.length() > text.length()) continue;
            for(int i = 0; i < text.length() - w.length() + 1; i++) {
                if(text.substr(i,w.length()) == w) res.push_back({i,i+(int)w.length() - 1});
            }
        }
        sort(begin(res), end(res));
        return res;
    }
};