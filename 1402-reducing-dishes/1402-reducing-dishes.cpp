class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        if(satisfaction.back() <= 0) return 0;
        vector<int> sum{0};
        int res = 0;
        for(auto& n : satisfaction) {
            sum.push_back(sum.back() + n);
            res += n * (sum.size() - 1);
        }
        for(int i = 0; i < sum.size(); i++) {
            if(sum.back() - sum[i] >= 0) break;
            res -= (sum.back() - sum[i]);
        }
        return res;
    }
 };