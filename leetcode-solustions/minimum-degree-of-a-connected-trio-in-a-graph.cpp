class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>> &edges) {
        vector<set<int>> nears(n + 1);
        vector<int> countOfNears(n + 1);
        for(auto &edge : edges) {
            nears[min(edge[0], edge[1])].insert(max(edge[0], edge[1]));
            countOfNears[edge[0]]++;
            countOfNears[edge[1]]++;
        }
        int res = INT_MAX;
        for(auto n1 = 1; n1 <= n; n1++)
            for(auto n2 = nears[n1].begin(); n2 != nears[n1].end(); n2++)
                for(auto n3 = next(n2); n3 != nears[n1].end(); n3++)
                    if(nears[*n2].count(*n3))
                        res = min(res, countOfNears[n1] + countOfNears[*n2] + countOfNears[*n3]);
        return res == INT_MAX ? -1 : res - 6;
    }
};
