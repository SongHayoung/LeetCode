class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> who(n,vector<int>(n));
        vector<int> cnts(artifacts.size() + 1);
        int now = 0, id = 1;
        for(auto& a : artifacts) {
            int y1 = a[0], y2 = a[2], x1 = a[1], x2 = a[3];
            for(int y = y1; y <= y2; y++) {
                for(int x = x1; x <= x2; x++) {
                    who[y][x] = id;
                    cnts[id]++;
                }
            }
            id++;
        }
        for(auto& d : dig) {
            int y = d[0], x = d[1];
            if(who[y][x]) {
                int p = who[y][x];
                who[y][x] = 0;
                if(--cnts[p] == 0) now++;
            }
        }
        
        return now;
    }
};