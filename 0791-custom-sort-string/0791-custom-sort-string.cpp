class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> ord;
        for(int i = 0; i < order.size(); i++) ord[order[i]] = i;
        sort(begin(s), end(s), [&](char a, char b) {
            return ord[a] < ord[b];
        });
        return s;
    }
};