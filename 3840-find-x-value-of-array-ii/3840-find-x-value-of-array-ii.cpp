struct Node {
    int prod;
    int freq[5];
} seg[404040];

Node merge(Node l, Node r, int mod) {
    Node res{.prod = l.prod * r.prod % mod, .freq = {0,0,0,0,0}};
    for(int i = 0; i < mod; i++) {
        res.freq[i] += l.freq[i];
        res.freq[l.prod * i % mod] += r.freq[i];
    }
    return res;
}
void init(int u, int x) {
    seg[u].prod = x;
    for(int i = 0; i < 5; i++) seg[u].freq[i] = i == seg[u].prod;
}
void build(vector<int>& A, int u, int s, int e, int mod) {
    if(s == e) init(u, A[s] % mod);
    else {
        int m = s + (e - s) / 2;
        build(A,u * 2, s, m, mod);
        build(A,u * 2 + 1, m + 1, e, mod);
        seg[u] = merge(seg[u*2], seg[u*2+1], mod);
    }
}
void update(int u, int n, int x, int s, int e, int mod) {
    if(s <= n and n <= e) {
        if(s == e) init(u, x);
        else {
            int m = s + (e - s) / 2;
            update(u * 2, n, x, s, m, mod);
            update(u * 2 + 1, n, x, m + 1, e, mod);
            seg[u] = merge(seg[u * 2], seg[u * 2 + 1], mod);
        }
    }
}
Node query(int u, int s, int e, int l, int r, int mod) {
    if(s > r or e < l) return Node{.prod = 1, .freq = {0,0,0,0,0}};
    if(l <= s and e <= r) return seg[u];
    int m = s + (e - s) / 2;
    return merge(query(u * 2, s, m, l, r, mod), query(u * 2 + 1, m + 1, e, l, r, mod), mod);
}
class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        build(nums,1,0,nums.size() - 1, k);
        vector<int> res;
        for(auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            update(1, idx, val % k, 0, nums.size() - 1, k);
            auto now = query(1, 0, nums.size() - 1, start, nums.size() - 1, k);
            res.push_back(now.freq[x]);
        }
        return res;
    }
};
