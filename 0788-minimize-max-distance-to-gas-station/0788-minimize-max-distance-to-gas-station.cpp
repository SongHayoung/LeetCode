class Solution {
public:
    double minmaxGasDist(vector<int>& st, int k) {
        int n = st.size();
        double l = 0, r = st[n-1]-st[0], m;
        while(l + 1e-6 < r) {
            double m = (l + r) / 2;
            int cnt = 0;
            for(int i = 0; i < n - 1; i++) {
                cnt += ceil((st[i+1] - st[i]) / m) - 1;
            }
            if(cnt > k) l = m;
            else r = m;
        }
        
        return r;
    }
};