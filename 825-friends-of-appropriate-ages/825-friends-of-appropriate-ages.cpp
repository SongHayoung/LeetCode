class Solution {
public:
    int numFriendRequests(vector<int>& A) {
        int res = 0;
        int freq[121] = {};
        for(auto& a : A) freq[a]++;
        for(int i = 15; i <= 120; i++) {
            for(int j = i * 0.5 + 8; j <= i; j++)
                res += freq[j] * (freq[i] - (i==j));
        }
        return res;
    }
};