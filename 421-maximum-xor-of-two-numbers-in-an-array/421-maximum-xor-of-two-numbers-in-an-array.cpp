struct Trie {
    Trie* next[2];
    Trie() {
        memset(next, 0, sizeof(next));
    }
};
class Solution {
    Trie* trie;
public:
    int findMaximumXOR(vector<int>& nums) {
        trie = new Trie();
        int res = 0;
        for(auto n : nums) insert(n);
        for(auto n : nums) res = max(res, search(n));
        return res;
    }
    void insert(int n) {
        Trie* node = trie;
        for(int i = 31; i >= 0; i--) {
            int bit = (n>>i) & 1;
            if(!node->next[bit]) node->next[bit] = new Trie();
            node = node->next[bit];
        }
    }
    int search(int n) {
        Trie* node = trie;
        int res = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (n>>i) & 1;
            if(node->next[!bit]) {
                res += (1<<i);
                node = node->next[!bit];
            } else node = node->next[bit];
        }
        return res;
    }
};