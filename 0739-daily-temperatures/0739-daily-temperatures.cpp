class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n), st;
        for(int i = n - 1; i >= 0; i--) {
            while(st.size() and temperatures[st.back()] <= temperatures[i]) st.pop_back();
            if(st.size()) res[i] = st.back() - i;
            st.push_back(i);
        }
        return res;
    }
};