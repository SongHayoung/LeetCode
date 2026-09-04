
struct Block {
    long long base, l, r;
    map<long long,long long> freq;
    vector<long long> A;
    Block(int l, int r) : base(0), l(l), r(r) {}
    void append(int x) {
        A.push_back(x);
        freq[x]++;
    }
    int lookup(long long x) {
        x -= base;
        if(freq.count(x)) return freq[x];
        return 0;
    }
    void udt(int le, int ri, int val) {
        if(le <= l and r <= ri) base += val;
        else {

            
              int from = max(le * 1ll, l) - l;
        int to = min(ri * 1ll, r) - l;

            for(int i = from; i <= to and i < A.size(); i++) {
                if(--freq[A[i]] == 0)
                    freq.erase(A[i]);
                A[i] += val;
                ++freq[A[i]];
            }
        }
    }
};
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<int> res;
        int sq = sqrt(nums2.size());
        vector<Block> b;
        for(int i = 0; i < nums2.size(); i++) {
            if(i % sq == 0) b.push_back(Block(i,i+sq-1));
            b.back().append(nums2[i]);
        }
        for(auto& q : queries) {
            if(q[0] == 1) {
                int l = q[1], r = q[2], val = q[3];
                for(int i = l / sq; i <= r / sq; i++) b[i].udt(l,r,val);
            } else {
                int now = 0, target = q[1];
                for(auto& block : b) {
                    for(auto& n : nums1) {
                        now += block.lookup(target - n);
                    }
                }
                res.push_back(now);
            }
        }
        return res;
    }
};