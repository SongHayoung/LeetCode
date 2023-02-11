class Solution {
    int gr[101][2];
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        memset(gr,-1,sizeof(gr));
        map<int, vector<int>> r, b;
        for(auto& e : redEdges) {
            r[e[0]].push_back(e[1]);
        }
        for(auto& e : blueEdges) {
            b[e[0]].push_back(e[1]);
        }
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({0, 1});
        gr[0][0] = gr[0][1] = 0;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int nxtColor = p.second ? 0 : 1;
            if(p.second) {
                //blue
                for(auto nxt : b[p.first]) {
                    if(gr[nxt][nxtColor] == -1) {
                        q.push({nxt, nxtColor});
                        gr[nxt][nxtColor] = gr[p.first][p.second] + 1;
                    }
                }
            } else {
                //red
                for(auto nxt : r[p.first]) {
                    if(gr[nxt][nxtColor] == -1) {
                        q.push({nxt, nxtColor});
                        gr[nxt][nxtColor] = gr[p.first][p.second] + 1;
                    }
                }
            }
        }
        
        vector<int> res(n, -1);
        res[0] = 0;
        for(int i = 1; i < n; i++) {
            int rc = gr[i][0];
            int bc = gr[i][1];
            if(rc != -1 and bc != -1) res[i] = min(rc, bc);
            else if(rc != -1) res[i] = rc;
            else if(bc != -1) res[i] = bc;
        }

        return res;
    }
};