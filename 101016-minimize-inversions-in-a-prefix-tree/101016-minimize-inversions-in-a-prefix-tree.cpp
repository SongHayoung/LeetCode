

pair<int,int> dp[1<<11];
int id = INT_MIN;

class Solution {
    int getCost(vector<int>& front, vector<int>& behind) {
        int res = 0;
        for(int i = 0, j = 0; i < front.size(); i++) {
            while(j < behind.size() and behind[j] < front[i]) j++;
            res += j;
        }
        return res;
    }
    int helper(vector<vector<int>>& cost) {
        int n = cost.size();
        if (n <= 1) return 0;

        int L = n / 2, R = n - L, NL = 1<<L, NR = 1<<R;

        vector<vector<int>> sumL(n, vector<int>(NL, 0));
        vector<vector<int>> sumR(n, vector<int>(NR, 0));

        for (int x = 0; x < n; x++) {
            for (int m = 1; m < NL; m++) {
                int b = __builtin_ctz(m);
                int pm = m & (m - 1);
                sumL[x][m] = sumL[x][pm] + cost[b][x];
            }
            for (int m = 1; m < NR; m++) {
                int b = __builtin_ctz(m);
                int pm = m & (m - 1);
                sumR[x][m] = sumR[x][pm] + cost[L + b][x];
            }
        }

        int FULL = 1 << n, INF = 1e9;
        id++;
        dp[0] = {id,0};

        for (int mask = 0; mask < FULL; mask++) {
            if(dp[mask].first != id) dp[mask] = {id,INF};
            int cur = dp[mask].second;
            if (cur == INF) continue;
            int ml = mask & (NL - 1);
            int mr = (mask >> L) & (NR - 1);
            int rem = (~mask) & (FULL - 1);
            while (rem) {
                int x = __builtin_ctz(rem);
                rem &= rem - 1;

                int add = sumL[x][ml] + sumR[x][mr];
                int nmask = mask | (1 << x);
                if(nmask >= FULL) continue;
                int nv = cur + add;
                if(dp[nmask].first != id) dp[nmask] = {id,INF};
                if (nv < dp[nmask].second) dp[nmask].second = nv;
            }
        }
        return dp[FULL - 1].second;
    }
    int dfs(vector<pair<string, int>>& A) {
        int res = 0;
        unordered_map<int,vector<pair<string,int>>> groups;
        int base = -1;
        vector<vector<int>> childs;
        unordered_map<char,int> assign;
        for(auto& [k,v] : A) {
            if(k == "") base = v;
            else {
                auto ch = k.back(); k.pop_back();
                if(!assign.count(ch)) {
                    assign[ch] = childs.size();
                    childs.emplace_back();
                }
                groups[ch].push_back({k,v});
                childs[assign[ch]].push_back(v);
            }
        }
        for(auto& [_,g] : groups) res += dfs(g);
        if(base != -1) {
            for(auto& [k,v] : A) if(v < base) res++;
        }

        int n = assign.size();
        vector<vector<int>> costs(n,vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                costs[i][j] = getCost(childs[i], childs[j]);
                costs[j][i] = getCost(childs[j], childs[i]);
            }
        }

        return res + helper(costs);
    }
public:
    int minInversions(vector<string>& words, vector<int>& target) {
        vector<pair<string, int>> ord;
        unordered_map<int,int> at;

        for(int i = 0; i < target.size(); i++) at[target[i]] = i;
        for(int i = 0; i < words.size(); i++) {
            reverse(begin(words[i]), end(words[i]));
            ord.push_back({words[i], at[i]});
        }
        sort(begin(ord), end(ord), [](auto& a, auto& b) {
            return a.second < b.second;
        });
        return dfs(ord);
    }
};