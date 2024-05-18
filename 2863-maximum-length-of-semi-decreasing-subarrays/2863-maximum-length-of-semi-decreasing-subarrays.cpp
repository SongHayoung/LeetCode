class Solution {
public:
    int maxSubarrayLength(vector<int>& A) {
        int n = A.size(), res = 0;
        vector<int> st{n-1};
        for(int i = n - 2; i >= 0; i--) {
            if(A[st.back()] > A[i]) st.push_back(i);
        }
        for(int i = 0; i < n - 1 and st.size(); i++) {
            while(st.size() and st.back() <= i) st.pop_back();
            while(st.size() and A[i] > A[st.back()]) {
                res = max(res, st.back() - i + 1);
                st.pop_back();
            }
        }
        return res;
    }
};