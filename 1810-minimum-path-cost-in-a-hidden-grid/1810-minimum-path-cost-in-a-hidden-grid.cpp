/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     int move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
    unordered_map<int, unordered_map<int,int>> g;
    int ty = INT_MAX, tx = INT_MAX;
    char d[4]{'U','L','D','R'};
    int dy[4]{-1,0,1,0},dx[4]{0,-1,0,1};
    bool vis(int y, int x) {
        return g.count(y) and g[y].count(x);
    }
    void rollBack(GridMaster& master, int dir) {
        if(dir == -1) return;
        master.move(d[(dir + 2)%4]);
    }
    void dfs(int y, int x, GridMaster &master, int dir) {
        if(master.isTarget()) {
            ty = y, tx = x;
        }
        for(int i = 0; i < 4; i++) {
            if(!master.canMove(d[i]) or vis(y + dy[i], x + dx[i])) continue;
            g[y+dy[i]][x+dx[i]] = master.move(d[i]);
            dfs(y + dy[i], x + dx[i], master, i);
        }
        
        rollBack(master, dir);
    }
    int bfs() {
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> q;
        q.push({0,0,0});
        int res = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [c,y,x] = q.top(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(g.count(ny) and g[ny].count(nx)) {
                        int nc = c + g[ny][nx];
                        g[ny].erase(nx);
                        if(ny == ty and nx == tx) return nc;
                        q.push({nc,ny,nx});
                    }
                }
            }
            res++;
        }
        return res;
    }
public:
    int findShortestPath(GridMaster &master) {
          dfs(0,0,master,-1);
        if(ty == INT_MAX) return -1;
        return bfs();
    }
};