class Solution {
    unordered_map<int, int> group;
    int island = 0;
    int find(int n) {
        if(!group.count(n)) group[n] = n, island++; //if there is no island, add island
        if(n != group[n]) group[n] = find(group[n]);
        return group[n];
    }
    void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        if(pa != pb) group[pa] = pb, island--; //merge two islands and remove 1
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        for(int i = 0; i < n; i ++) {
            merge(stones[i][0], ~stones[i][1]);
        }
        return n - island;
    }
};