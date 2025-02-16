struct Seg {
    pair<long long, long long> range;
    long long cnt, val;
    Seg *left, *right;
    Seg(vector<long long>& A, int l, int r) : range({A[l], A[r]}), cnt(0), val(0), left(nullptr), right(nullptr) {
        if(r - l > 1) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m,r);
        }
    }
    void update(int l, int r, int op) {
        if(range.first >= r or range.second <= l) return;
        if(l <= range.first and range.second <= r) {
            cnt += op;
        } else {
            left->update(l,r,op);
            right->update(l,r,op);
        }

        if(cnt) {
            val = range.second - range.first;
        } else {
            val = 0;
            if(left) val += left->val;
            if(right) val += right->val;
        }
    }
};
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<array<int,4>> lines;
        vector<long long> pos;
        for(auto& s : squares) {
            int x1 = s[0], y1 = s[1], x2 = x1 + s[2], y2 = y1 + s[2];
            pos.push_back(x1);
            pos.push_back(x2);
            lines.push_back({y1,1,x1,x2});
            lines.push_back({y2,-1,x1,x2});
        }
        sort(begin(lines), end(lines));
        sort(begin(pos), end(pos));
        pos.erase(unique(begin(pos), end(pos)), end(pos));

        long double area = 0., last = 0., now = 0.;
        Seg* seg = new Seg(pos,0,pos.size() - 1);
        for(auto& [y,op,l,r] : lines) {
            area += (y - last) * seg->val / 2.;
            seg->update(l,r,op);
            last = y;
        }
        last = 0.;
        for(auto& [y,op,l,r] : lines) {
            long double nxt = now + (y - last) * seg->val;
            
            if(now <= area and area <= nxt) {
                return last + (area - now) / seg->val;
            }
            
            seg->update(l,r,op);
            last = y;
            now = nxt;
        }
        return -1.;
    }
};