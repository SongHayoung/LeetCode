class Solution {
public:
    int minimumSeconds(vector<vector<string>>& land) {
        int n = land.size(), m = land[0].size();
        queue<pair<int,int>> at;
        queue<pair<int,int>> water;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(land[i][j] == "*") water.push({i,j});
            if(land[i][j] == "S") at.push({i,j});
        }
        int res = 0;
        auto inc = [&](int y, int x) {return 0 <= y and y < n and 0 <= x and x < m;};
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        while(at.size()) {
            int wsz = water.size();
            while(wsz--) {
                auto [y,x] = water.front(); water.pop();
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(inc(ny,nx) and land[ny][nx] != "*" and land[ny][nx] != "D" and land[ny][nx] != "X") {
                        if(land[ny][nx] == "D") return -1;
                        land[ny][nx] = "*";
                        water.push({ny,nx});
                    }
                }
            }
            int asz = at.size();
            while(asz--) {
                auto [y,x] = at.front(); at.pop();
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(inc(ny,nx) and (land[ny][nx] == "." or land[ny][nx] == "D")) {
                        if(land[ny][nx] == "D") return res + 1;
                        land[ny][nx] = "S";
                        at.push({ny,nx});
                    }
                }
            }
            res += 1;
        }
        return -1;
    }
};