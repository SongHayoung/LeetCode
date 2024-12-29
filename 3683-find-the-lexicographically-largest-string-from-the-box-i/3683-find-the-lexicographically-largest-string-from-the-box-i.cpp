vector<int> SA(string& s) {
    int n = s.size(), t = 1;
    vector<int> sa(n), tg(n + 1), g(n + 1);
    for(int i = 0; i < n; i++) sa[i] = i, g[i] = s[i]-'a';
    while(t <= n) {
        g[n] = -1;
        auto cmp = [&](int x, int y) {
            if(g[x] == g[y]) return g[x + t] < g[y + t];
            return g[x] < g[y];
        };

        sort(begin(sa), end(sa), cmp);

        tg[sa[0]] = 0;
        for(int i = 1; i < n; i++) tg[sa[i]] = tg[sa[i-1]] + cmp(sa[i-1], sa[i]);

        swap(g,tg);
        t <<= 1;
    }
    return sa;
}

class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        vector<int> sa = SA(word);
        int len = word.size() - numFriends + 1;
        string res = "";
        return word.substr(sa.back(), len);
    }
};