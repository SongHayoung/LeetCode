class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, n = height.size();
        vector<pair<int,int>> st;
        for(int i = 0; i < n; i++) {
            int h = height[i], at = i;
            while(st.size() and st.back().second <= h) {
                int width = i - st.back().first;
                int base = st.back().second;
                at = st.back().first;
                st.pop_back();
                if(st.size()) {
                    res += width * (min(st.back().second, h) - base);
                }
            }
            st.push_back({at, h});
        }
        return res;
    }
};