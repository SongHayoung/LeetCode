class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        A.push_back(0);
        int res = 0;
        vector<pair<int, int>> st;
        for(int i = 0; i < A.size(); i++) {
            int at = i;
            while(st.size() and st.back().second >= A[i]) {
                auto [p,h] = st.back(); st.pop_back();
                res = max(res, h * (i - p));
                at = p;
            }
            st.push_back({at, A[i]});
        }
        return res;
    }
};