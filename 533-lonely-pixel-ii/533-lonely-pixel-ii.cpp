class Solution {
    string toString(vector<char>& A) {
        string res = "";
        for(auto& a : A) res.push_back(a);
        return res;
    }
public:
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        vector<string> P;
        vector<int> rsum, csum;
        for(auto& pic : picture) {
            P.push_back(toString(pic));
            int s = 0;
            for(auto& pp : pic) s += pp == 'B';
            rsum.push_back(s);
        }
        int n = picture.size(), m = picture[0].size(), res = 0;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < m; i++) {
            int s = 0;
            for(int j = 0; j < n; j++) {
                s += picture[j][i] == 'B';
                if(picture[j][i] == 'B') mp[i].push_back(j);
            }
            csum.push_back(s);
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(picture[i][j] == 'W') continue;
                if(rsum[i] != target or csum[j] != target) continue;
                bool pass = true;
                for(auto& v : mp[j]) {
                    if(P[v] == P[i]) continue;
                    pass = false;
                    break;
                }
                
                res += pass;
            }
        }
        return res;
    }
};