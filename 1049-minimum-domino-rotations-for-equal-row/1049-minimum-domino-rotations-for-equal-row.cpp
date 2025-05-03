class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int res = INT_MAX;
        int tp[6]{0,}, bo[6]{0,}, switchtp[6]{0,}, switchbo[6]{0,};
        for(int i = 0; i < n; i++) {
            tp[tops[i] - 1]++;
            bo[bottoms[i] - 1]++;
            if(tops[i] != bottoms[i]) {
                switchbo[tops[i]-1]++;
                switchtp[bottoms[i]-1]++;
            }
        }
        for(int i = 0; i < 6; i++) {
            if(switchbo[i] + bo[i] == n) {
                res = min(res, switchbo[i]);
            }
            if(switchtp[i] + tp[i] == n) {
                res = min(res, switchtp[i]);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};