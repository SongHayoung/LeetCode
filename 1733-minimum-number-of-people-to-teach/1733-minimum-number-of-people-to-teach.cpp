class Solution {
    unordered_map<int, unordered_set<int>> speak;
    int adj[555][555] = {};
    void connect(int u, int v) {
        if(speak[u].size() > speak[v].size()) swap(u,v);
        for(auto& s : speak[u]) {
            if(speak[v].count(s)) {
                adj[u][v] = adj[v][u] = true;
                break;
            }
        }
    }
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        for(int i = 0; i < languages.size(); i++) {
            speak[i+1] = unordered_set<int>(begin(languages[i]), end(languages[i]));
        }
        for(auto& f : friendships) {
            int u = f[0], v = f[1];
            connect(u, v);
        }
        int res = INT_MAX;
        for(int lang = 1; lang <= n; lang++) {
            int now = 0;
            vector<int> learn(languages.size() + 1);
            for(auto& f : friendships) {
                int u = f[0], v = f[1];
                if(adj[u][v]) continue;
                if(!speak[u].count(lang) and !learn[u]) {
                    learn[u] = true;
                    now++;
                }
                if(!speak[v].count(lang) and !learn[v]) {
                    learn[v] = true;
                    now++;
                }
            }
            res = min(res,now);
        }
        return res;
    }
};