class Solution {
    int findParent(vector<int>& g, int i) {
        return g[i] == i ? i : g[i] = findParent(g,g[i]);
    }
    void compare(vector<int>& g, int i, int j, string& s1, string& s2) {
        int pi = findParent(g, i), pj = findParent(g, j);
        if(pi == pj) return;

        int len = s1.length();
        char ch1, ch2;
        int diff = 0;
        for(int i = 0; i < len; i++) {
            if(s1[i] == s2[i]) continue;
            switch (++diff) {
                case 1: ch1 = s1[i], ch2 = s2[i]; break;
                case 2: if(s2[i] != ch1 or s1[i] != ch2) return; break;
                default: return;
            }
        }
        if(diff == 1) return;
        g[pi] = g[pj] = min(pi, pj);
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        vector<int> gr(strs.size());
        for(int i = 0; i < strs.size(); i++) gr[i] = i;
        for(int i = 0; i < strs.size(); i++)
            for(int j = i + 1; j < strs.size(); j++)
                compare(gr,i,j,strs[i],strs[j]);
        unordered_set<int> res;
        for(int i = 0; i < strs.size(); i++)
            res.insert(findParent(gr, i));

        return res.size();
    }
};