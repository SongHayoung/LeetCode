class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int l = 0, r = 0, len = s.length();
        while(r < len) {
            while(r != len - 1 and s[r] == s[r+1]) r++;
            if(r - l + 1 >= 3) res.push_back({l, r});
            r++;
            l = r;
        }
        return res;
    }
};