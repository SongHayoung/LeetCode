struct Seg {
    int l, r, ma;
    Seg *left, *right;
    Seg(int le, int ri) : l(le), r(ri), ma(0), left(nullptr), right(nullptr) {
        if(l ^ r) {
            int m = l + (r - l) / 2;
            left = new Seg(l,m);
            right = new Seg(m+1,r);
        }
    } 
    void update(int n, int x) {
        if(l <= n and n <= r) {
            ma = max(ma, x);
            if(left) left->update(n,x);
            if(right) right->update(n,x);
        }
    }
    int query(int le, int ri) {
        if(le <= l and r <= ri) return ma;
        if(l > ri or r < le) return 0;
        return max(left->query(le,ri), right->query(le,ri));
    }
};
class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        int ma = *max_element(begin(nums), end(nums));
        vector<vector<int>> groups(ma + 1);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= i) {
                groups[nums[i]].push_back(i - nums[i]);
            }
        }

        Seg* seg = new Seg(0, nums.size());
        int res = 0;

        for (int v = 0; v <= ma; v++) {
            vector<pair<int,int>> upd;
            for (int d : groups[v]) {
                int now = seg->query(0, d) + 1;
                upd.push_back({d, now});
                res = max(res, now);
            }
            for (auto& [d, now] : upd) {
                seg->update(d, now);
            }
        }

        return res;
    }
};