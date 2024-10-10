class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size(), res = 0;
        vector<int> st;
        for(int i = 0; i < n; i++) {
            if(st.empty() or A[st.back()] > A[i]) st.push_back(i);
        }
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() and A[st.back()] <= A[i]) {
                res = max(res, i - st.back());
                st.pop_back();
            }
        }
        return res;
    }
};