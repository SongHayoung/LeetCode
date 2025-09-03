class Solution {
public:
    int numberOfPairs(vector<vector<int>>& A) {
        int res = 0;
        for(int i = 0; i < A.size(); i++) swap(A[i][0], A[i][1]);
        sort(A.begin(), A.end(), [&](auto& a, auto& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        map<int,int> p;
        for (int i = 0; i < A.size(); i++) {
            int y = A[i][0], x = A[i][1], best = INT_MIN;
            for(auto it = p.lower_bound(x); it != end(p); it++) {
                if(it->second > best) {
                    res++, best = it->second;
                }
            }
            
            p[x] = y; 
        }
        return res;
    }
};