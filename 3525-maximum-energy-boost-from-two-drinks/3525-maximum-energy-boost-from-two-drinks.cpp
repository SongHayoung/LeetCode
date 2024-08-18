class Solution {
public:
    long long maxEnergyBoost(vector<int>& profitsA, vector<int>& profitsB) {
         int n = profitsA.size();
        deque<long long> dpA(3), dpB(3);
        for(int i = 0; i < n; i++) {
            dpA[0] += profitsA[i];
            dpB[0] += profitsB[i];
            if(i + 2 < n) {
                dpB[2] = dpA[0];
                dpA[2] = dpB[0];
            }
            if(i + 1 < n) {
                dpA[1] = max(dpA[1], dpA[0]);
                dpB[1] = max(dpB[1], dpB[0]);
                dpA.push_back(0);
                dpB.push_back(0);
                dpA.pop_front();
                dpB.pop_front();
            }
        }
        return max(dpA[0],dpB[0]);
    }
};