class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<int> freq(26);
        vector<pair<int,char>> A;
        for(int i = 0; i < s.length(); i++) {
            int x = points[i][0], y = points[i][1];
            int z = max(abs(x), abs(y));
            A.push_back({z,s[i]});
        }
        sort(rbegin(A), rend(A));
        int res = 0;
        int cnt = 0;
        bool ok = true;
        while(A.size() and ok) {
            int x = A.back().first;
            while(A.size() and A.back().first == x) {
                auto [_,ch] = A.back(); A.pop_back();
                if(++freq[ch-'a'] >= 2) ok = false;
                cnt++;
            }
            if(ok) res = cnt;
        }
        return res;
    }
};