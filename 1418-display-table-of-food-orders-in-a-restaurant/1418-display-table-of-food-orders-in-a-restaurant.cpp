class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, unordered_map<string, int>> mp;
        set<string> foods;
        for(auto& o : orders) {
            string no = o[1], food = o[2];
            mp[stoi(no)][food]++;
            foods.insert(food);
        }
        vector<vector<string>> res(mp.size() + 1, vector<string>(foods.size() + 1, "0"));
        res[0][0] = "Table";
        unordered_map<string, int> fmp;
        int pos = 1;
        for(auto f : foods) {
            fmp[f] = pos;
            res[0][pos++] = f;
        }
        pos = 1;
        for(auto& [o, foods] : mp) {
            res[pos][0] = to_string(o);
            for(auto& [f,cnt] : foods) {
                res[pos][fmp[f]] = to_string(cnt);
            }
            pos++;
        }
        
        return res;
    }
};