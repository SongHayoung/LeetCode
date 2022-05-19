class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](vector<int>& a, vector<int>& b) {
           if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> st;
        for(auto& a : A) {
            int n = a[1];
            if(st.empty() or st.back() < n) st.push_back(n);
            else {
                auto lb = lower_bound(begin(st), end(st), n);
                *lb = n;
            }
        }
        return st.size();
    }
};