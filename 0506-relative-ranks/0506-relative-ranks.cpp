class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> ord(score.size());
        for(int i = 0; i < ord.size(); i++) ord[i] = i;
        sort(begin(ord), end(ord), [&](int i, int j) {
            return score[i] > score[j];
        });
        vector<string> res(score.size());
        vector<string> medal{"Gold ", "Silver ", "Bronze "};
        for(int i = 0; i < ord.size(); i++) {
            if(i <= 2) {
                res[ord[i]] = medal[i] + "Medal";
            } else res[ord[i]] = to_string(i+1);
        }
        return res;
    }
};