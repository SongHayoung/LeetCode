class Solution {
public:
    int minimumDeletions(vector<int>& A) {
        int mi = min_element(begin(A), end(A)) - begin(A), ma = max_element(begin(A), end(A)) - begin(A);
        int l = min(mi, ma), r = max(mi, ma), n = A.size();
        return min({l + 1 + n - r, r + 1, n - l});
    }
};