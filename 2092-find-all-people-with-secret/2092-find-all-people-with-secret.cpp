class Solution {
    vector<int> uf;
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = min(pu, pv);
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        uf = vector<int>(n);
        for(int i = 0; i < n; i++) uf[i] = i;
        uni(0, firstPerson);
        
        sort(begin(meetings), end(meetings), [](vector<int>& m1, vector<int>& m2) {
            return m1[2] < m2[2];
        });
        
        int m = meetings.size(), i = 0;
        
        while(i < m) {
            int time = meetings[i][2];
            unordered_set<int> us;
            while(i < m and meetings[i][2] == time) {
                uni(meetings[i][0], meetings[i][1]);
                us.insert(meetings[i][0]);
                us.insert(meetings[i][1]);
                i++;
            }
            for(auto& u : us) {
                if(find(u)) uf[u] = u;
            }
        }
        
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(find(i)) continue;
            res.push_back(i);
        }
        
        return res;
    }
};