long long grid[22][22], dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
int cost[1<<10][20][20];
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        memset(grid,-1,sizeof grid);
        memset(cost,-1,sizeof cost);
        unordered_map<int,vector<pair<int,int>>> at;
        unordered_set<char> allow{'S','L'};
        int n = classroom.size(), m = classroom[0].size(), id = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(allow.count(classroom[i][j])) {
                    at[classroom[i][j]].push_back({i,j});
                }
            }
        }
        auto assign = [&](char ch) {
            if(!at.count(ch)) return;
            for(auto& [y,x] : at[ch]) grid[y][x] = id++;
        };
        assign('L');
        long long s = at['L'].size(), masking = (1<<s) - 1;
        queue<array<long long,4>> q;
        auto push = [&](long long mask, long long y, long long x, long long e) {
            if(cost[mask][y][x] < e) {
                cost[mask][y][x] = e;
                q.push({mask, y,x,e});
            }
        };
        push(0,at['S'][0].first, at['S'][0].second, energy);
        int res = 0;
        if(!masking) return 0;
        while(q.size()) {
            int qsz = q.size();
            while(qsz--) {
                auto [mask,y,x,e] = q.front(); q.pop();
                if(mask == masking) return res;
                if(cost[mask][y][x] != e) continue;
                if(!e) continue;
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m and classroom[y][x] != 'X') {
                        if(classroom[ny][nx] == 'L') {
                            push(mask | (1<<grid[ny][nx]), ny, nx, e - 1);
                        } else if(classroom[ny][nx] == 'R') {
                            push(mask,ny,nx,energy);
                        } else push(mask,ny,nx,e-1);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};