class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;
        vector<pair<int, int>> st;
        // (height , position)
        for(int i = 0; i < height.size(); i++) {
            int p = i, h = height[i];
            while(st.size() >= 2 and st.back().first <= h) {
                auto [bottomHeight, bottomPosition] = st.back(); st.pop_back();
                area += (i - bottomPosition) * (min(st.back().first, h) - bottomHeight);
                p = bottomPosition;
            }
            
            if(st.size() == 1) {
                if(st.back().first <= h) {
                    st.pop_back();
                    p = i;
                }
            }
            
            st.push_back({h,p});
        }
        
        return area;
    }
};