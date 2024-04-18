class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> freq(121);
        for(auto a : ages) freq[a]++;
        int res = 0;
        for(int x = 1; x < 121; x++) {
            if(!freq[x]) continue;
            for(int y = x * 0.5 + 8; y <= x; y++) {
                if(!freq[y]) continue;
                res += freq[y] * (freq[x] - (x == y));
            }
        }
        return res;
    }
};