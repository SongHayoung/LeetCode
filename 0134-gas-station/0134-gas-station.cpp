class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<pair<int, int>> st;
        int n = gas.size(), now = 0;
        for(int i = 0; i < 2 * n; i++) {
            while(st.size() and st.back().second > now) st.pop_back();
            st.push_back({i,now});
            int g = gas[i % n], c = cost[i % n];
            now = now + g - c;
            if(st.back().first - st.front().first >= n) return i % n;
        }
        return -1;
    }
};