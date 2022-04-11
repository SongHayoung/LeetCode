class Solution {
    unordered_map<string, int> dp;
    int backTracking(vector<unordered_map<char,int>>& sticker, string target) {
        if(dp.count(target)) return dp[target];
        dp[target] = 987654321;
        unordered_map<char,int> req;
        for(auto ch : target)
            req[ch]++;
        
        for(auto st : sticker) {
            if(!st.count(target[0])) continue;
            string nTarget = "";
            for(auto [ch, count] : req) {
                if(count - st[ch] > 0) {
                    nTarget += string(count - st[ch], ch);
                }
            }
            dp[target] = min(dp[target], 1 + backTracking(sticker, nTarget));
        }
        return dp[target];
    }
    
public:
    int minStickers(vector<string>& stickers, string target) {
        unordered_map<char,int> t;
        for(auto ch : target) t[ch]++;
        
        vector<unordered_map<char,int>> sticker;
        for(auto st : stickers) {
            unordered_map<char,int> tmp;
            tmp.reserve(t.size());
            for(auto ch : st) {
                if(t.count(ch)) {
                    tmp[ch]++;
                }
            }
            if(!tmp.empty())
                sticker.push_back(tmp);
        }
        dp[""] = 0;
        int res = backTracking(sticker,target);
        return res > target.length() ? -1 : res;
    }
};