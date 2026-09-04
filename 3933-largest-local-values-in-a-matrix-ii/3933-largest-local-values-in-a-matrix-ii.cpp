
int fenwick[202][202];
void update(int i, int j) {
    for(int x = i + 1; x < 202; x += x & -x) {
        for(int y = j + 1; y < 202; y += y & -y) {
            fenwick[x][y] += 1;
        }
    }
}
int query(int i, int j) {
    int res = 0;
    for(int x = i + 1; x; x -= x & -x) {
        for(int y = j + 1; y; y -= y & -y) {
            res += fenwick[x][y];
        }
    }
    return res;
}
int query(int y1, int x1, int y2, int x2) {
    int res = query(y2,x2);
    if(y1 > 0) res -= query(y1 -1, x2);
    if(x1 > 0) res -= query(y2, x1 - 1);
    if(y1 > 0 and x1 > 0) res += query(y1 - 1, x1 - 1);
    return res;
}

class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        priority_queue<array<int,3>,vector<array<int,3>>> q;
        int n = matrix.size(), m = matrix[0].size();
        memset(fenwick, 0, sizeof fenwick);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
                if(matrix[i][j]) q.push({matrix[i][j],i,j});
            }
        int res = 0;
        while(q.size()) {
            int x = q.top()[0];
            queue<pair<int,int>> qq;
            while(q.size() and q.top()[0] == x) {
                auto [_,i,j] = q.top(); q.pop();
                int y1 = i - x, y2 = i + x, x1 = j - x, x2 = j + x;
                int sum = query(max(0,y1), max(0,x1), min(n-1,y2), min(m-1,x2));
                for(auto& py : {y1,y2}) for(auto& px : {x1,x2}) {
                    if(0 <= py and py < n and 0 <= px and px < m and matrix[py][px] > x) sum--;
                }
                res += sum == 0;
                qq.push({i,j});

            }
            while(qq.size()) {
                auto [i,j] = qq.front(); qq.pop();
                update(i,j);
            }
        }
        return res;
    }
};