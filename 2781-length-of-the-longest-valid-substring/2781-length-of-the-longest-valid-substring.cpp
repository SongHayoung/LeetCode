class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> us(begin(forbidden), end(forbidden));
        vector<int> best(word.length(), INT_MAX), suf(word.length(), INT_MAX), at(word.length());
        for(int r = 0; r < word.length(); r++) {
            string now = "";
            for(int j = 1; j + r <= word.length() and j <= 10; j++) {
                now.push_back(word[r+j-1]);
                if(us.count(now)) {
                    best[r] = r + j - 2;
                    if(r + j - 2 >= 0) at[r+j-2] = max(at[r+j-2], r);
                    break;
                }
            }
        }
        suf.back() = best.back();
        for(int i = word.length() - 2; i >= 0; i--) {
            suf[i] = min(best[i], suf[i+1]);
        }
        int res = 0;
        for(int l = 0, r = 0; r < word.length();) {
            int no = suf[r];
            if(no == INT_MAX) no = word.length() - 1;
            res = max(res, no - l + 1);
            if(no == word.length() - 1) break;
            if(no < r) r = l = r + 1;
            else r = l = at[no] + 1;
        }
        return res;
    }
};

