class Solution {
    string sort(string str) {
        std::sort(begin(str), end(str));
        return str;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;
        for(auto& str : strs) {
            m[sort(str)].push_back(str);
        }
        for(auto& entity : m) {
            res.push_back(entity.second);
        }
        return res;
    }
};