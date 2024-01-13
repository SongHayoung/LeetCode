class Solution {
public:
    int countDivisibleSubstrings(string word) {
        vector<pair<int, int>> dp;
        vector<int> cost{1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9};
        int res = 0;
        for(int i = 0; i < word.length(); i++) {
            int c = cost[word[i]-'a'];
            for(auto& [k,v] : dp) {
                k += c;
                if(k % (i - v + 1) == 0) res += 1;
            }
            dp.push_back({c,i});
        }
        return res + word.length();
    }
};