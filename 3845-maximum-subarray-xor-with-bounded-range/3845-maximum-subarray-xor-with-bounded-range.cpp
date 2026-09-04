
struct Seg {
    int mi, ma, val;
    Seg *le, *ri;
    Seg(vector<int>& A, int l, int r) : mi(A[l]), ma(A[r]), val(-1), le(nullptr), ri(nullptr) {
        if(l ^ r) {
            int m = l + (r - l) / 2;
            le = new Seg(A,l,m);
            ri = new Seg(A,m+1,r);
        }
    }
    void update(int x, int at) {
        if(mi <= x and x <= ma) {
            val = at;
            if(le) le->update(x,at);
            if(ri) ri->update(x,at);
        }
    }
    int query(int l, int r) {
        if(l <= mi and ma <= r) return val;
        if(l > ma or r < mi) return -1;
        return max(le->query(l,r), ri->query(l,r));
    }
};
struct Trie {
    Trie* next[2];
    int count;
    Trie() : count(0) {
        memset(next,0,sizeof next);
    }
    void insert(int x, int b = 31) {
        count++;
        if(b == -1) return;
        int fl = (x>>b) & 1;
        if(!next[fl]) next[fl] = new Trie();
        next[fl]->insert(x,b-1);
    }
    int query(int x, int b = 31) {
        if(b == -1) return 0;
        int fl = (x>>b) & 1;
        if(!next[!fl] or next[!fl]->count == 0) return next[fl]->query(x,b-1);
        return (1<<b) + next[!fl]->query(x,b-1);
    }
    void erase(int x, int b = 31) {
        count--;
        if(b == -1) return;
        int fl = (x>>b) & 1;
        next[fl]->erase(x,b-1);
    }
};
class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        vector<long long> xors{0};
        long long op = 0;
        for(auto& n : nums) {
            op ^= n;
            xors.push_back(op);
        }
        int until = 0;
        vector<int> S = nums;
        S.push_back(INT_MIN);
        S.push_back(INT_MAX);
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        Seg* seg = new Seg(S,0,S.size() - 1);
        Trie* t = new Trie();
        t->insert(0);
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int now = max({until, seg->query(INT_MIN,n-k-1), seg->query(n+k+1, INT_MAX)});
            while(until < now) t->erase(xors[until++]);
            res = max(res, t->query(xors[i+1]));
            t->insert(xors[i+1]);
            seg->update(n,i+1);
        }
        return res;
    }
};