class Leaderboard {
    unordered_map<int, int> m;
    multiset<int> ms;
public:
    Leaderboard() {

    }

    void addScore(int p, int s) {
        auto it = ms.find(m[p]);
        if(it != ms.end()) ms.erase(it);
        m[p] += s;
        ms.insert(m[p]);
    }

    int top(int K) {
        int res(0), i(0);
        for(auto it = ms.rbegin(); it != ms.rend() && i < K; it++) {
            res += *it; i++;
        }
        return res;
    }

    void reset(int p) {
        auto it = ms.find(m[p]);
        if(it != ms.end()) ms.erase(it);
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