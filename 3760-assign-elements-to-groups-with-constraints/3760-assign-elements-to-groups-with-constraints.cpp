class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        unordered_set<int> E,G(begin(groups), end(groups));
        vector<vector<int>> rgroups(101010);
        vector<int> res(groups.size(), -1);
        for(int i = 0; i < groups.size(); i++) rgroups[groups[i]].push_back(i);
        for(int i = 0; i < elements.size(); i++) {
            int e = elements[i];
            if(E.count(e)) continue;
            for(int j = e; j <= 1e5; j += e) {
                if(!G.count(j)) continue;
                while(rgroups[j].size()) {
                    auto idx = rgroups[j].back(); rgroups[j].pop_back();
                    res[idx] = i;
                }
                G.erase(j);
            }
            E.insert(e);
        }

        return res;
    }
};