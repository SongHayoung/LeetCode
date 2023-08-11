class Solution {
public:
    bool isPreorder(vector<vector<int>>& nodes) {
        if(nodes[0][1] != -1) return false;
        vector<int> st{nodes[0][0]};
        for(int i = 1; i < nodes.size(); i++) {
            while(st.size() and st.back() != nodes[i][1]) st.pop_back();
            if(st.size() == 0) return false;
            st.push_back(nodes[i][0]);
        }
        
        return true;
    }
};