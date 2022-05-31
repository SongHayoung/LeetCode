class Solution {
    vector<string> helper(string& a, string& o) {
        int i = 0, n = a.length();
        for(; i < n and o[i] == a[i]; i++) {};
        vector<string> res;
        for(int j = i + 1; j < n; j++) {
            if(a[j] == o[i]) {
                swap(a[j], a[i]);
                res.push_back(a);
                swap(a[j], a[i]);
            }
        }
        return res;
    }
public:
    int kSimilarity(string s1, string s2) {
        if(s1 == s2) return 0;
        queue<string> q;
        q.push(s1);
        int res = 1;
        unordered_set<string> vis{s1};
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto s = q.front(); q.pop();
                for(auto& nxt : helper(s, s2)) {
                    if(vis.count(nxt)) continue;
                    if(nxt == s2) return res;
                    q.push(nxt);
                    vis.insert(nxt);
                }
            }
            res++;
        }
        return -1;
    }
};