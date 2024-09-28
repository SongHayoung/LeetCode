class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        if(word2.size() == 1) return {0};
        int n = word1.size(), m = word2.size();
        vector<int> suf(n + 1, m);
        for(int i = n - 1, j = m - 1; i >= 0; i--) {
            if(j >= 0 and word1[i] == word2[j]) --j;
            suf[i] = j + 1;
        }
        vector<int> res;
        for(int i = 0, j = 0, fl = false; i < word1.size() and res.size() < m; i++) {
            if(word1[i] == word2[j]) res.push_back(i), j++;
            else {
                if(fl) continue;
                if((m - suf[i+1]) + j + 1 >= m) {
                    res.push_back(i), j++;
                    fl = !fl;
                }
            }
        }
        if(res.size() != m) return {};
        return res;
    }
};