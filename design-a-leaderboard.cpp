class Leaderboard {
    unordered_map<int, int> m;
public:
    Leaderboard() {

    }

    void addScore(int p, int s) {
        m[p] += s;
    }

    int top(int K) {
        vector<pair<int, int>> topK(K);
        partial_sort_copy(begin(m),end(m),begin(topK),end(topK),[](const pair<const int, int>& p1, const pair<const int, int>& p2) { return p1.second > p2.second; });
        int res(0);
        for(auto& t : topK) res += t.second;
        return res;
    }

    void reset(int p) {
        m[p] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
