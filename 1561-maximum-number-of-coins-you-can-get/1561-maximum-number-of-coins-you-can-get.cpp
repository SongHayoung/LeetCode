class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int res = 0, pick = piles.size() / 3;
        sort(begin(piles), end(piles));
        for(int i = piles.size() - 2; pick; i -= 2, pick -= 1)
            res += piles[i];
        return res;
    }
};