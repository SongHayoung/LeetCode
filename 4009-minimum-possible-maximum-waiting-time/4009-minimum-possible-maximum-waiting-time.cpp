class Solution {
    int INF = 1e9;
    int states = 51 * 21 * 21;

    int encode(int f1, int t1, int t2) {
        return (f1 * 21 + t1) * 21 + t2;
    }

    array<int, 4> decode(int state, int fuelSum, int usedFuel) {
        int t2 = state % 21;
        state /= 21;

        int t1 = state % 21;
        int f1 = state / 21;
        int f2 = fuelSum - usedFuel - f1;

        return {f1, f2, t1, t2};
    }

public:
    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
        if(demand[0] > max(fuel[0], fuel[1])) return -1;
        vector<int> dp(states, INF), dpp(states, INF);
        vector<int> cur, nxt;

        int fuelSum = fuel[0] + fuel[1];
        int usedFuel = 0;

        int initialState = encode(fuel[0], 0, 0);
        dp[initialState] = 0;
        cur.push_back(initialState);

        for(int idx = 0; idx < demand.size(); idx++) {
            fill(dpp.begin(), dpp.end(), INF);
            nxt.clear();

            int d = demand[idx];

            for(int state : cur) {
                auto [f1, f2, t1, t2] = decode(
                        state,
                        fuelSum,
                        usedFuel
                );

                if(f1 >= d) {
                    int nextState = encode(f1 - d,d,max(0, t2 - t1));
                    int nextWait = max(dp[state], t1);
                    if(dpp[nextState] == INF) {
                        nxt.push_back(nextState);
                    }

                    dpp[nextState] = min(dpp[nextState], nextWait);
                }

                if(f2 >= d) {
                    int nextState = encode(f1,max(0, t1 - t2),d);
                    int nextWait = max(dp[state], t2);
                    if(dpp[nextState] == INF) {
                        nxt.push_back(nextState);
                    }

                    dpp[nextState] = min(dpp[nextState], nextWait);
                }
            }

            if(nxt.empty()) break;
            usedFuel += d;
            dp.swap(dpp);
            cur.swap(nxt);
        }

        int res = INF;
        for(int state : cur) res = min(res, dp[state]);
        return res;
    }
};