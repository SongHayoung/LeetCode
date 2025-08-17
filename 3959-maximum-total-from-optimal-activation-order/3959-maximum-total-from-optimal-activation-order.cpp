class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        long long res = 0;
        unordered_map<int,vector<int>> vals;
        for(int i = 0; i < value.size(); i++) {
            vals[limit[i]].push_back(value[i]);
        }
        for(auto& [k,v] : vals) {
            sort(rbegin(v), rend(v));
            for(int i = 0; i < k and i < v.size(); i++) res += v[i];
        }
        return res;
    }
};