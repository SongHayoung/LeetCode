class Solution {
public:
    int trap(vector<int>& A) {
        vector<pair<int,int>> st;
        int res = 0;
        for(int i = 0; i < A.size(); i++) {
            int at = i;
            while(st.size() and st.back().second <= A[i]) {
                auto [pos, h] = st.back(); st.pop_back();
                at = pos;
                if(st.size()) {
                    int w = i - at;
                    res += w * (min(A[i], st.back().second) - h);
                }
            }
            st.push_back({at,A[i]});
        }
        return res;
    }
};