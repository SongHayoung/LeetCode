class Solution {
public:
    int candy(vector<int>& ratings) {
        int sz = ratings.size(), res(0);
        vector<int> candy(sz, 1);
        for(int i = 1; i < sz; i++) {
            if(ratings[i] > ratings[i - 1]) candy[i] += candy[i - 1];
        }
        for(int i = sz - 2; i >= 0; res += candy[i], i--) {
            if(ratings[i] > ratings[i + 1]) candy[i] = max(candy[i + 1] + 1, candy[i]);
        }
        return res + candy.back();
    }
};