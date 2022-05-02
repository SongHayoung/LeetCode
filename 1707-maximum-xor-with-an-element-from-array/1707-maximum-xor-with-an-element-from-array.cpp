struct Trie{
    Trie* next[2];
    Trie() {memset(next, 0, sizeof next);}
    void insert(int n, int p = 30) {
        if(p == -1) return ;
        bool bi = n & (1<<p);
        if(!next[bi]) next[bi] = new Trie();
        next[bi]->insert(n, p - 1);
    }
    int query(int x, int n, int p = 30, bool exceed = false) {
        if(p == -1) return exceed ? 0 : -1;
        if(exceed) {
            bool nbi = n & (1<<p);
            
            if(next[!nbi])
                return (1<<p) ^ next[!nbi]->query(x,n,p-1,true);
            
            return next[nbi]->query(x,n,p-1,true);
        } else {
            bool xbi = x & (1<<p);
            if(xbi) {
                int res = -1;
                if(next[1]) {
                    int ans = next[1]->query(x,n,p-1,false);
                    if(ans != -1) {
                        bool nbi = n & (1<<p);
                        res = max(res, ans ^ (nbi ? 0 : (1<<p)) );
                    }
                }
                if(next[0]) {
                    res = max(res,  (n & (1<<p)) ^ next[0]->query(x,n,p-1,true));
                }
                return res;
            } else {
                if(!next[0]) return -1;
                int ans = next[0]->query(x,n,p-1,false);
                if(ans != -1) {
                    ans ^= n & (1<<p);
                }
                return ans;
            }
        }
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int mi = INT_MAX;
        unordered_set<int> A;
        vector<int> res;
        Trie* t = new Trie();
        for(auto& n : nums) {
            mi = min(mi,n);
            t->insert(n);
            A.insert(n);
        }
        for(auto& q : queries) {
            int x = q[0], m = q[1];
            if(m < mi) res.push_back(-1);
            else {
                int ans = t->query(m,x);
                if(A.count(m)) ans = max(ans, m ^ x);
                res.push_back(ans);
            }
        }
        return res;
    }
};