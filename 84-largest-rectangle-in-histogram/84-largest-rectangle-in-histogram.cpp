class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        //index, height pair
        vector<pair<int, int>> st;
        int area = 0;
        for(int i = 0; i < h.size(); i++) {
            int lastIndex = i;
            while(!st.empty() and st.back().second > h[i]) {
                area = max(area, st.back().second * (i - st.back().first));
                lastIndex = st.back().first;
                st.pop_back();
            }
            st.push_back({lastIndex, h[i]});
        }
        
        while(!st.empty()) {
            area = max(area, (int)(st.back().second * (h.size() - st.back().first)));
            st.pop_back();
        }
        return area;
    }
};