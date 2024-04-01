class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), tank = 0;
        vector<pair<int, int>> st;
        for(int i = 0; i < 2 * n; i++) {
            if(i < n) {
                st.push_back({i,tank});
            }
            tank = tank + gas[i%n] - cost[i%n];
            while(st.size() and st.back().second > tank) st.pop_back();
            if(i >= n) {
                if(st.size() and st.front().first <= i - n) return st.front().first;
            }
        }
        return -1;
    }
};