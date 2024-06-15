class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& P, vector<int>& C) {
        vector<pair<int, int>> S;
        for(int i = 0; i < P.size(); i++) S.push_back({C[i], P[i]});
        sort(rbegin(S), rend(S));
        priority_queue<int> q;
        auto add = [&]() {
            while(S.size() and S.back().first <= w) {
                q.push(S.back().second);
                S.pop_back();
            }
        };
        add();
        for(int i = 0; i < k and q.size(); i++) {
            w += q.top(); q.pop();
            add();
        }
        return w;
    }
};