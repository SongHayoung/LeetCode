class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char, long long> startWith;
        unordered_map<string, unordered_set<int>> notSwapWith;
        for(auto& i : ideas) {
            startWith[i[0]]++;
            notSwapWith[i.substr(1)].insert(i[0]);
        }

        long long res = 0;
        long long dp[26][26] = {};

        for(auto& i : ideas) {
            string suf = i.substr(1);
            auto& us = notSwapWith[suf];
            for(char c = 'a'; c <= 'z'; c++) {
                if(us.count(c)) continue;
                dp[c-'a'][i[0] - 'a']++;
            }
        }

        for(auto& i : ideas) {
            string suf = i.substr(1);
            auto& us = notSwapWith[suf];
            for(char c = 'a'; c <= 'z'; c++) {
                if(us.count(c)) continue;
                res += dp[i[0]-'a'][c-'a'];
            }
        }


        return res;
    }
};