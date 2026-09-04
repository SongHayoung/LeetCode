
struct Seg {
    int mi,ma;
    int head,tail,cnt;
    Seg *left, *right;

    Seg(string& s, int l, int r) : mi(l), ma(r), head(s[l] == 'A'), tail(s[r] == 'A'), cnt(0), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(s,l,m);
            right = new Seg(s,m+1,r);
            cnt = left->cnt + right->cnt + (left->tail == right->head);
        }
    }
    void update(int n, int x) {
        if(mi <= n and n <= ma) {
            if(mi == n and n == ma) {
                head = tail = x;
                return;
            }
            left->update(n,x);
            right->update(n,x);
            head = left->head, tail = right->tail;
            cnt = left->cnt + right->cnt + (left->tail == right->head);
        }
    }
    array<int,3> query(int l, int r) {
        if(l <= mi and ma <= r) return {head,tail,cnt};
        if(l > ma or r < mi) return {-1,-1,0};
        auto [leHead, leTail, leCnt] = left->query(l,r);
        auto [riHead, riTail, riCnt] = right->query(l,r);
        if(leHead == -1) return {riHead, riTail, riCnt};
        if(riHead == -1) return {leHead, leTail, leCnt};
        int now = leCnt + riCnt + (leTail == riHead);
        return {leHead, riTail, now};
    }
};

class Solution {
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        Seg* seg = new Seg(s,0,s.length() - 1);
        vector<int> res;
        for(auto& q : queries) {
            int op = q[0];
            if(op == 1) {
                int idx = q[1];
                s[idx] = s[idx] == 'A' ? 'B' : 'A';
                seg->update(idx,s[idx] == 'A');
            } else {
                int l = q[1], r = q[2];
                auto [head,tail,sum] = seg->query(l,r);
                assert(head != -1);
                assert(tail != -1);
                res.push_back(sum);
            }
        }
        return res;
    }
};