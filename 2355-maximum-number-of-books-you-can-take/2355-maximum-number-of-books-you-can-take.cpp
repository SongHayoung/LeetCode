class Solution {
    long long helper(long long p, long long c) {
        return (p * (p + 1) - (p > c ? (p - c) * (p - c + 1) : 0)) / 2;
    }
public:
    long long maximumBooks(vector<int>& A) {
        long long res = 0, now = 0;
        vector<int> st;
        
        for(int i = 0; i < A.size(); i++) {
            while(!st.empty() and A[i] - A[st.back()] < i - st.back()) {
                int j = st.back(); st.pop_back();
                now -= helper(A[j], st.empty() ? j + 1 : j - st.back());
            }
            now += helper(A[i], st.empty() ? i + 1 : i - st.back());
            st.push_back(i);
            res = max(res, now);
        }
        return res;
    }
};