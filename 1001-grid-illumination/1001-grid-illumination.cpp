struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};
class Solution {
    unordered_map<int, unordered_set<pair<int,int>, pair_hash>> R, C, D, RD;
    int getRK(pair<int,int> p) {
        return p.first;
    }
    int getCK(pair<int,int> p) {
        return p.second;
    }
    int getDK(pair<int,int> p) {
        return p.first - p.second;
    }
    int getRDK(pair<int,int> p) {
        return p.first + p.second;
    }
    void insert(pair<int,int> l) {
        R[getRK(l)].insert(l);
        C[getCK(l)].insert(l);
        D[getDK(l)].insert(l);
        RD[getRDK(l)].insert(l);
    }
    bool qry(pair<int,int> l) {
        return !R[getRK(l)].empty() or !C[getCK(l)].empty() or !D[getDK(l)].empty() or !RD[getRDK(l)].empty();
    }
    void _remove(pair<int,int> l) {
        R[getRK(l)].erase(l);
        C[getCK(l)].erase(l);
        D[getDK(l)].erase(l);
        RD[getRDK(l)].erase(l);
    }
    void remove(vector<int> l) {
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                _remove(make_pair(l[0] + i, l[1] + j));
            }
        }
    }
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> res(q);
        for(auto& l : lamps)
            insert({l[0],l[1]});
        for(int i = 0; i < q; i++) {
            res[i] = qry({queries[i][0], queries[i][1]});
            remove(queries[i]);
        }
        return res;
    }
};