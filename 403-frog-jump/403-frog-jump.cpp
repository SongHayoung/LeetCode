class Solution {
    unordered_set<long> st;
    unordered_map<string, bool> dp;
    int goal;
    string makeKey(int f, int u) {
        return to_string(f) + '#' + to_string(u);
    }
    bool jump(long frog, long unit) {
        if(frog == goal) return true;
        string key = makeKey(frog, unit);
        if(dp.count(key)) return dp[key];
        bool res = false;
        for(int i = max(1l, unit-1); i <= unit + 1 and !res; i++) {
            if(st.count(frog + i)) res |= jump(frog + i, i);
        }
        return dp[key] = res;
    }
public:
    bool canCross(vector<int>& stones) {
        if(stones[0] + 1 != stones[1]) return false;
        goal = stones.back();
        st.insert(stones.begin(), stones.end());
        return jump(stones[1],1);
    }
};