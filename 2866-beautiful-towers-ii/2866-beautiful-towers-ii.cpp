class Solution {
public:
    long long maximumSumOfHeights(vector<int>& A) {
        int n = A.size();
        vector<long long> dpl(n), dpr(n);
        vector<pair<long long, long long>> st;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            int pos = i;
            while(st.size() and st.back().first > A[i]) {
                auto [val, p] = st.back(); st.pop_back();
                sum -= val * (pos - p);
                pos = p;
            }
            dpl[i] = sum;
            sum += 1ll * A[i] * (i - pos + 1);
            st.push_back({A[i], pos});
        }
        st.clear();
        sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            int pos = i;
            while(st.size() and st.back().first > A[i]) {
                auto [val, p] = st.back(); st.pop_back();
                sum -= val * (p - pos);
                pos = p;
            }
            dpr[i] = sum;
            sum += 1ll * A[i] * (pos - i + 1);
            st.push_back({A[i], pos});
        }
        long long res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, dpl[i] + dpr[i] + A[i]);
        }
        return res;
    }
};
