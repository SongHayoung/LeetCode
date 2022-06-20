class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int ma = 0, c = 0, res = 0;
        for(auto& f : flips) {
            ma = max(ma, f);
            c++;
            if(ma == c) res++;
        }
        return res;
    }
};