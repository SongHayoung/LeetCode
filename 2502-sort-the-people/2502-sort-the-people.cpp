class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> S;
        for(int i = 0; i < names.size(); i++) {
            S.push_back({heights[i], names[i]});
        }        
        sort(begin(S), end(S));
        vector<string> res;
        for(int i = S.size() - 1; i >= 0; i--) res.push_back(S[i].second);
        return res;
    }
};
