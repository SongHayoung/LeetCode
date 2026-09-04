
struct Trie {
#define BIT(a,i) (((a)>>(i))&1)
    Trie* next[2];
    int cnt;
    Trie(): cnt(0) { next[0]=next[1]=nullptr; }
    void insert(long long x, int bit) {
        cnt++;
        if (bit < 0) return;
        int b = BIT(x, bit);
        if (!next[b]) next[b] = new Trie();
        next[b]->insert(x, bit - 1);
    }
    long long countLess(long long x, long long K, int bit) {
        if (!this || bit < 0) return 0;
        int xb = BIT(x, bit), kb = BIT(K, bit);
        if (kb) {
            long long res = 0;
            if (next[xb]) res += next[xb]->cnt;
            if (next[1 - xb]) {
                long long Ksub = K & ((1LL << bit) - 1);
                res += next[1 - xb]->countLess(x, Ksub, bit - 1);
            }
            return res;
        } else {
            return next[xb] ? next[xb]->countLess(x, K, bit - 1) : 0;
        }
    }
    long long query(long long x, long long K, int maxBit) {
        return cnt - countLess(x, K, maxBit);
    }
};
class Solution {
public:
    long long countXorSubarrays(vector<int>& nums, int k) {
        Trie* t = new Trie();
        long long bit = 0, res = 0, ma = 31;
        t->insert(bit,ma);
        for(auto& a : nums) {
            bit ^= a;
            long long now = t->query(bit,k,ma);
            res += now;
            t->insert(bit,ma);
        }
        return res;
    }
};