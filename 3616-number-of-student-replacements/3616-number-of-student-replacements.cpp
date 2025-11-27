class Solution {
public:
    int totalReplacements(vector<int>& ranks) {
        int best = ranks[0], res = 0;
        for(int i = 1; i < ranks.size(); i++) {
            if(best > ranks[i]) {
                best = ranks[i];
                res++;
            }
        }
        return res;
    }
};