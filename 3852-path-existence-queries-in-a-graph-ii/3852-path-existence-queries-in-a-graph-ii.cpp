
int uf[101010];
int find(int u) {
    return uf[u] == u ? u : uf[u] = find(uf[u]);
}
void uni(int u, int v) {
    int pu = find(u), pv = find(v);
    uf[pu] = uf[pv] = min(pu,pv);
}
struct Nodes {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
    int jump, at;
    Nodes(int at) : jump(0), at(at) {}

    void merge(Nodes* oth, vector<int>& res) {
        while(oth->q.size()) {
            auto [u,id] = oth->q.top(); oth->q.pop();
            res[id] += oth->jump - jump + 1;
            if(u > at) q.push({u,id});
            else res[id] += jump;
        }
    }
    void add(int u, int id, vector<int>& res) {
        res[id] = -jump;
        q.push({u,id});
    }
    void update(int att, vector<int>& res) {
        at = att;
        jump++;
        clean(res);
    }
    void clean(vector<int>& res) {
        while(q.size() and q.top().first <= at) {
            auto [u,id] = q.top(); q.pop();
            res[id] += jump;
        }
    }
};
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> ord(n), rord(n);
        iota(begin(ord), end(ord), 0);
        iota(begin(uf), end(uf), 0);
        sort(begin(ord), end(ord), [&](int i, int j) {
            return nums[i] < nums[j];
        });
        for(int i = 0; i < n; i++) {
            if(i and nums[ord[i]] <= nums[ord[i-1]] + maxDiff) uni(ord[i], ord[i-1]);
            rord[ord[i]] = i;
        }
        vector<int> S = nums;
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        unordered_map<int,int> mp;
        for(int i = n - 1; i >= 0; i--) {
            if(!mp.count(nums[ord[i]])) mp[nums[ord[i]]] = ord[i];
        }
        vector<vector<pair<int,int>>> QQ(n);
        vector<int> res(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            int u = queries[i][0], v = queries[i][1];
            if(u == v) continue;
            if(find(u) != find(v)) res[i] = -1;
            else {
                if(nums[u] > nums[v]) swap(u,v);
                if(nums[u] + maxDiff >= nums[v]) res[i] = 1;
                else QQ[rord[u]].push_back({nums[v], i});
            }
        }
        vector<Nodes*> nodes(n, nullptr);
        auto go = [&](int x) {
            int at = *prev(upper_bound(begin(S), end(S), x + maxDiff));
            return at;
        };
        for(int i = 0; i < n; i++) {
            int u = ord[i];
            for(auto& [until, id] : QQ[i]) {
                if(nodes[i] == nullptr) nodes[i] = new Nodes(nums[u]);
                nodes[i]->add(until, id, res);
            }
            if(nodes[i] == nullptr) continue;
            nodes[i]->clean(res);
            int val = go(nums[u]), v = rord[mp[val]];
            if(nodes[v] == nullptr) {
                swap(nodes[i], nodes[v]);
                nodes[v]->update(val, res);
            } else {
                nodes[v]->merge(nodes[i], res);
            }
        }
        return res;
    }
};