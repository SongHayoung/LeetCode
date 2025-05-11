class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int> freq;
        for(auto& ch : s) freq[ch]++;
        vector<int> S;
        for(auto& [_,v] : freq) S.push_back(v);
        int res = 0;
        sort(rbegin(S), rend(S));
        while(S.size() > k) {
            res += S.back(); S.pop_back();
        }
        return res;
    }
};
