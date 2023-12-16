class Solution {
    int findMaxArea(vector<int>& A) {
        int n = A.size(), best = 0;
        vector<pair<int,int>> st;
        for(int i = 0; i < A.size(); i++) {
            int h = A[i], w = 1;
            while(st.size() and st.back().first >= h) {
                w += st.back().second;
                best = max(best, st.back().first * (w - 1));
                st.pop_back();
            }            
            best = max(best, w * h);
            st.push_back({h,w});
        }
        
        int width = A.size();
        for(auto& [h,w] : st) {
            best = max(best, h * width);
            width -= w;
        }
        
        return best;
    }
public:
    int maximalRectangle(vector<vector<char>>& A) {
        int n = A.size(), m = A[0].size(), res = 0;
        vector<int> dp(m, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == '0') dp[j] = 0;
                else dp[j] += 1;
            }
            res = max(res, findMaxArea(dp));
        }
        return res;
    }
};