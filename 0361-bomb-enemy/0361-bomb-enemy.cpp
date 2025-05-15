class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& A) {
        int res = 0, n = A.size(), m = A[0].size();
        vector<vector<int>> kill(n,vector<int>(m));
        for(int i = 0; i < n; i++) {
            vector<int> who;
            int cnt = 0;
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 'W') {
                    while(who.size()) {
                        kill[i][who.back()] += cnt;
                        who.pop_back();
                    }
                    cnt = 0;
                } else if(A[i][j] == 'E') {
                    cnt++;
                } else who.push_back(j);
            }
            while(who.size() and cnt) {
                        kill[i][who.back()] += cnt;
                        who.pop_back();
                    }
        }
        for(int j = 0; j < m; j++) {
            vector<int> who;
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(A[i][j] == 'W') {
                    while(who.size()) {
                        kill[who.back()][j] += cnt;
                        who.pop_back();
                    }
                    cnt = 0;
                } else if(A[i][j] == 'E') cnt++;
                else who.push_back(i);
            }
            while(who.size() and cnt) {
                kill[who.back()][j] += cnt;
                who.pop_back();
            }
                    
        }
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) res = max(res, kill[i][j]);
        return res;
    }
};