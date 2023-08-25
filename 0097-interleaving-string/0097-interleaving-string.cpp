class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1len(s1.length()), s2len(s2.length());
        bool v[101][101]{true,};
        queue<pair<int, int>> q;
        q.push({0,0});

        while(!q.empty()) {
            auto p = q.front(); q.pop();
            if(p.first < s1len && s3[p.first + p.second] == s1[p.first] && !v[p.first + 1][p.second]) {
                v[p.first + 1][p.second] = true;
                q.push({p.first + 1, p.second});
            }
            if(p.second < s2len && s3[p.first + p.second] == s2[p.second] && !v[p.first][p.second + 1]) {
                v[p.first][p.second + 1] = true;
                q.push({p.first, p.second + 1});
            }
        }

        return s1len + s2len == s3.length() && v[s1len][s2len];
    }
};