class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        const string PUSH = "Push";
        const string POP = "Pop";
        for(int i = 0, now = 1; i < target.size(); i++) {
            while(now != target[i]) {
                res.push_back(PUSH);
                res.push_back(POP);
                now++;
            }
            res.push_back(PUSH);
            now++;
        }
        return res;
    }
};