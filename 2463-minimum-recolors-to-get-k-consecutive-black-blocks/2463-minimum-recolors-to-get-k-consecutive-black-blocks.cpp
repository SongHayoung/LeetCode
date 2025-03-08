class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res = INT_MAX, l = 0, r = 0, n = blocks.length(),  now = 0;
        for(int i = 0; i < blocks.size(); i++) {
            if(blocks[i] == 'B') now++;
            if(i >= k and blocks[i-k] == 'B') now--;
            if(i + 1 >= k) res = min(res, k - now);
        }
        return res;
    }
};