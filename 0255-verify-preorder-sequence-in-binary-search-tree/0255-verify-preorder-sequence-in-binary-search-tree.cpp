class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int l = INT_MIN;
        vector<int> st;
        for(auto& p : preorder) {
            if(l > p) return false;
            while(!st.empty() and st.back() < p) {
                l = st.back(); st.pop_back();
            }
            st.push_back(p);
        }
        return true;
    }
};