class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> res;
        unordered_map<string, int> ind;
        unordered_map<string, vector<string>> adj;
        int n = recipes.size();
        for(int i = 0; i < n; i++) {
            string rep = recipes[i];
            auto& ing = ingredients[i];
            ind[rep] = ing.size();
            for(auto& in : ing) {
                adj[in].push_back(rep);
            }
        }
        
        queue<string> q;
        for(auto& su : supplies)
            q.push(su);
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            for(auto& v : adj[u]) {
                if(--ind[v] == 0) {
                    q.push(v);
                    res.push_back(v);
                }
            }
        }
        return res;
    }
};