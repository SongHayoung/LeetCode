class Solution {
public:
    int longestAwesome(string s) {
        int n = s.length(), res = 0;
        unordered_map<int, int> lookup{{0,-1}};
        
        for(int i = 0, dp = 0; i < n; i++) {
            dp ^= (1<<(s[i] & 0b1111));
            
            if(lookup.count(dp))
                res = max(res, i - lookup[dp]);
            else lookup[dp] = i;
            
                for(int j = 0; j < 10; j++) {
                    int submask = dp ^ (1<<j);
                    if(lookup.count(submask))
                        res = max(res, i - lookup[submask]);
                }
        }
        
        return res;
    }
};