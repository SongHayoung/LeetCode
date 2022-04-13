class Solution {
    int getFlower(int n) {
        for(int i = 1; i <= 4; i++) {
            if(!(n & (1<<i))) return i;
        }
        return -1;
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> conn(n);
        vector<int> res(n,0);
        vector<int> near(n,0);
        for(auto p : paths) {
            conn[p[0] - 1].push_back(p[1] - 1);
            conn[p[1] - 1].push_back(p[0] - 1);
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(res[i] == 0) {
                q.push(i);
                while(!q.empty()) {
                    auto g = q.front(); q.pop();
                    int flower = getFlower(near[g]);
                    res[g] = flower;
                    for(auto nxt : conn[g]) {
                        if(res[nxt] == 0) {
                            near[nxt] |= (1<<flower);
                            q.push(nxt);
                        }
                    }    
                }
            }
        }
        return res;
    }
};