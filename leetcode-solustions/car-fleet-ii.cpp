class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> res(cars.size(),-1);
        stack<int> st;
        st.push(cars.size() - 1);
        for(int i = cars.size() - 2; i >= 0; --i) {
            while(st.size() && cars[i][1] <= cars[st.top()][1]) st.pop();
            double& t = res[i];
            while(st.size()) {
                t = 1.0 * (cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);
                if(res[st.top()] == -1 || res[st.top()] >= t) break;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
