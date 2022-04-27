struct Trie{
    Trie* next[2];
    int count = 0;
    Trie() {
        memset(next,0,sizeof(next));
    }
    void insert(int n, int bi = 15) {
        count++;
        if(bi < 0) return;
        
        bool mask = n & (1<<bi);
        if(!next[mask]) next[mask] = new Trie();
        next[mask]->insert(n, bi - 1);
    }
    
    int query(int n, int k, int bi = 15) {
        if(bi < 0) return 0;
        bool nbi = n & (1<<bi), kbi = k & (1<<bi);
        int res = 0;
        if(kbi) {
            if(nbi) {
                res += (next[1] ? next[1]->count : 0);
                res += (next[0] ? next[0]->query(n,k,bi-1) : 0);
            } else {
                res += (next[0] ? next[0]->count : 0);
                res += (next[1] ? next[1]->query(n,k,bi-1) : 0);
            }
        } else {
            if(nbi) {
                res += (next[1] ? next[1]->query(n,k,bi-1) : 0);
            } else {
                res += (next[0] ? next[0]->query(n,k,bi-1) : 0);
            }
        }
        return res;
    }
};
class Solution {
public:
    int countPairs(vector<int>& A, int low, int high) {
        int res = 0;
        Trie* trie = new Trie();
        for(auto& a : A) {
            res += trie->query(a, high + 1) - trie->query(a, low);
            trie->insert(a);
        }
        return res;
    }
};