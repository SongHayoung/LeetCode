class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<pair<int, int>> st;
        int n = gas.size(), now = 0;
        for(int i = 0; i < 2 * n; i++) {
            st.push_back({i,now});
            int g = gas[i % n], c = cost[i % n];
            now = now + g - c;
            while(st.size() and st.back().second > now) st.pop_back();
            int at = (i + 1);
            if(st.size() and (i + 1) - st.front().first >= n) return (i + 1) % n;
        }
        return -1;
    }
};