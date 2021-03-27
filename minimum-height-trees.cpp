class Solution {
    int height = INT_MAX;
    int getChildHeight(int from, int me, vector<list<pair<int, int>>>& g) {
        int res = 0;
        for(auto& child : g[me]) {
            if(child.first != from) {
                if(child.second == -1) {
                    res = max(res, child.second = getChildHeight(me, child.first, g));
                } else {
                    res = max(res, child.second);
                }
            }
        }
        return res + 1;
    }

    int getHeight(int root, vector<list<pair<int, int>>>& g) {
        int res = 0;
        for(auto& child : g[root]) {
            res = max(res, getChildHeight(root, child.first, g));
        }
        return res;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<list<pair<int, int>>> g(n, list<pair<int,int>>());
        for(auto edge : edges) {
            g[edge[0]].push_back({edge[1], -1});
            g[edge[1]].push_back({edge[0], -1});
        }

        for(int i = 0; i < n; i++) {
            int level = getHeight(i, g);
            if(level == height) {
                res.push_back(i);
            } else if(level < height) {
                height = level;
                res.clear();
                res.push_back(i);
            }
        }

        return res;
    }
};
