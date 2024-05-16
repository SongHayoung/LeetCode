class Solution {
public:
    int trap(vector<int>& A) {
        int res = 0;
        vector<pair<int,int>> st;
        for(int i = 0; i < A.size(); i++) {
            int p = i;
            while(st.size() and st.back().second <= A[i]) {
                auto [at,h] = st.back(); st.pop_back();
                if(st.size() == 0) break;
                int w = (i - at);
                int x = min(A[i],st.back().second) - h;
                res += w * x;
                p = at;
            }
            st.push_back({p,A[i]});
        }
        return res;
    }
};