class Solution {
public:
    long long maxPoints(vector<int>& reward1, vector<int>& reward2, int k) {
        long long res = accumulate(begin(reward1), end(reward1), 0ll);
        vector<long long> D;
        for(long long i = 0; i < reward1.size(); i++) D.push_back(reward2[i] - reward1[i]);
        sort(begin(D), end(D));
        while(D.size() > k and D.back() > 0 ) {
            res += D.back(); D.pop_back();
        }
        return res;
    }
};