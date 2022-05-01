class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> st;
        int sum = 0;
        for(int n : arr) {
            while(!st.empty() and st.back() <= n) {
                int mi = st.back();
                st.pop_back();
                sum += min(n, st.empty() ? INT_MAX : st.back()) * mi;
            }
            st.push_back(n);
        }
        for(int i = 0; i < st.size() - 1; i++) {
            sum += st[i] * st[i+1];
        }
        return sum;
    }
};