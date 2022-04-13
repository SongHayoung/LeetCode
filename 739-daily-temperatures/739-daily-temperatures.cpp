class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> st;
        vector<int> res(T.size(), 0);
        for(int i = T.size() - 1; i >= 0; i--) {
            while(!st.empty() and T[st.back()] <= T[i]) st.pop_back();
            if(!st.empty()) {
                res[i] = st.back() - i;
            }
            st.push_back(i);
        }
        return res;
    }
};