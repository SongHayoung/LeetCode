class Solution {
    int g[26];
    int find(int n) {
        return g[n] == n ? n : g[n] = find(g[n]);
    }
    void uni(int a, int b) {
        int pa = find(a), pb = find(b);
        g[pa] = g[pb] = min(pa, pb);
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i = 0; i < 26; i++) g[i] = i;
        for(int i = 0; i < s1.length(); i++) {
            uni(s1[i] - 'a', s2[i] - 'a');
        }
        for(int i = 0; i < baseStr.length(); i++) {
            baseStr[i] = 'a' + find(baseStr[i]-'a');
        }
        return baseStr;
    }
};