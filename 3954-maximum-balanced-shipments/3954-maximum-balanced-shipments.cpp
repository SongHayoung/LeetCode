class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int res = 0, n = weight.size();
        for(int i = 1, best = weight[0]; i < n; i++) {
            if(best > weight[i]) {
                res++;
                if(i + 1 < n) best = weight[++i];
            } else best = weight[i];
        }
        return res;
    }
};