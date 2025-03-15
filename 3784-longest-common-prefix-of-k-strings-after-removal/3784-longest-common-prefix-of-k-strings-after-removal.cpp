class Solution {
    int helper(string& a, string& b) {
        int res = 0;
        for(; res < a.length() and res < b.length() and a[res] == b[res]; res++) {}
        return res;
    }
    pair<vector<int>,int> helper(vector<string>& S, vector<int>& ord, int k) {
        vector<int> best{0,0};
        int bestIndex = -1, n = S.size();
        for(int i = k - 1, j = 0; i < n; i++,j++) {
            int ii = ord[i], jj = ord[j];

            if(min(S[ii].length(), S[jj].length()) <= best[1]) continue;
            int match = helper(S[ii], S[jj]);
            if(match <= best[1]) continue;
            
            if(match > best[0]) swap(match, best[0]), bestIndex = i;
            if(match > best[1]) swap(match, best[1]);
        }

        return {best, bestIndex};
    }
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        if(words.size() <= k) return vector<int>(words.size());
        int n = words.size();
        vector<int> ord(n);
        for(int i = 0; i < n; i++) ord[i] = i;
        sort(begin(ord), end(ord), [&](int& i, int& j) {return words[i] < words[j];});
        auto [best, bestIndex] = helper(words,ord,k);
        vector<int> rord(n);
        vector<int> res(n, best[0]);
        if(best[0] != best[1]) {
            for(int i = bestIndex - k + 1; i <= bestIndex; i++) {
                res[ord[i]] = best[1];
            }
        }
        return res;
    }
};