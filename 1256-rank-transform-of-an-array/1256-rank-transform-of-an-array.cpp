class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> S = arr;
        sort(begin(S), end(S));
        unordered_map<int,int> mp;
        for(int i = 0, ord = 1; i < S.size(); i++) {
            if(!i or S[i] != S[i-1]) {
                mp[S[i]] = ord++;
            }
        }
        for(auto& x : arr) x = mp[x];
        return arr;
    }
};