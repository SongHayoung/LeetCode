class Solution {
public:
    int findTheDistanceValue(vector<int>& A, vector<int>& B, int d) {
        int n = A.size(), m = B.size();
        sort(begin(B), end(B));
        int res = 0;
        for(auto& a : A) {
            int lo = a - d;
            auto it = lower_bound(begin(B), end(B), lo);
            if(it == end(B) or *it > a + d) res++;
        }
        return res;
    }
};