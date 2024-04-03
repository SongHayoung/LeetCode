class Solution {
public:
    int maxSubarrayLength(vector<int>& A) {
        vector<int> st;
        int n = A.size(), res = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(st.empty() or A[st.back()] > A[i]) st.push_back(i);
        }
        for(int i = 0, mi = INT_MIN; i < n and st.size(); i++) {
            while(st.size() and st.back() <= i) st.pop_back();
            while(st.size() and A[i] > A[st.back()]) {
               res = max(res, st.back() - i + 1);
                st.pop_back();
            }
        }
        return res;
    }
};