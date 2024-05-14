bool bits(int x, int p) {
    return (x>>p) & 1;
}
struct Trie {
    Trie* t[2];
    int cnt = 0;
    Trie(): cnt(0) {
        memset(t, 0, sizeof t);
    }
    int query(int l, int r, int mask, int bit, int x) {
        int mi = mask, ma = mask ^ (((1ll<<(bit + 1)) - 1));
        if(l <= mi and ma <= r) return cnt;
        if(mi > r) return 0;
        if(ma < l) return 0;
        int res = 0;
        int b = bits(x,bit);
        if(t[0]) res += t[0]->query(l,r,mask ^ (b<<bit),bit-1,x);
        if(t[1]) res += t[1]->query(l,r,mask ^ ((!b)<<bit), bit-1,x);
        return res;
    }
    void insert(int x, int p = 20) {
        cnt++;
        if(p == -1) return;
        if(!t[bits(x,p)]) t[bits(x,p)] = new Trie();
        t[bits(x,p)]->insert(x,p-1);
    }
};
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        Trie* t = new Trie();
        int res = 0;
        for(auto& x : nums) {
            res += t->query(low,high,0,20,x);
            t->insert(x);
        }
        return res;
    }
};