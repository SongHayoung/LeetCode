class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        int res = 0;
        for(int i = 0, j = 0; i < g.size() and j < s.size(); i++) {
            while(j < s.size() and g[i] > s[j]) j++;
            if(j == s.size()) break;
            j += 1, res += 1;
        }
        return res;
    }
};