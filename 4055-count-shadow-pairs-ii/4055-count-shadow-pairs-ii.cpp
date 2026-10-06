struct Seg {
    int mi, ma;
    int mx, second, cnt;
    Seg *left, *right;

    Seg(int l, int r) : mi(l), ma(r), mx(INT_MIN), second(INT_MIN), cnt(r - l + 1), left(nullptr), right(nullptr) {
        if(l ^ r) {
            int m = l + (r - l) / 2;
            left = new Seg(l, m);
            right = new Seg(m + 1, r);
        }
    }

    void pull() {
        if(left->mx == right->mx) {
            mx = left->mx;
            second = max(left->second, right->second);
            cnt = left->cnt + right->cnt;
        } else if(left->mx > right->mx) {
            mx = left->mx;
            second = max(left->second, right->mx);
            cnt = left->cnt;
        } else {
            mx = right->mx;
            second = max(left->mx, right->second);
            cnt = right->cnt;
        }
    }

    void apply(int val) {
        mx = val;
    }

    void push() {
        if(left->mx > mx) left->apply(mx);
        if(right->mx > mx) right->apply(mx);
    }

    long long update(int l, int r, int val) {
        if(l > r or r < mi or ma < l or mx < val) return 0;

        if(l <= mi and ma <= r and second < val) {
            long long res = cnt;
            if(mx > val) apply(val);
            return res;
        }

        push();

        long long res = left->update(l, r, val);
        res += right->update(l, r, val);

        pull();
        return res;
    }

    void setValue(int pos, int val) {
        if(mi == ma) {
            mx = val;
            second = INT_MIN;
            cnt = 1;
            return;
        }

        push();

        if(pos <= left->ma) left->setValue(pos, val);
        else right->setValue(pos, val);

        pull();
    }
};

class Solution {
public:
    int shadowPairs(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> order;
        for(int i = 0; i < n; i++) {
            order.push_back({nums[i], i});
        }

        sort(order.begin(), order.end());

        vector<int> pos(n);
        for(int i = 0; i < n; i++) {
            pos[order[i].second] = i;
        }

        Seg* seg = new Seg(0, n - 1);
        long long res = 0;

        for(int j = 0; j < n; j++) {
            int right = lower_bound(order.begin(),order.end(),pair<int, int>{nums[j], -1}) - order.begin() - 1;

            if(right >= 0) {
                res += seg->update(0, right, nums[j]);
            }

            seg->setValue(pos[j], INT_MAX);
        }

        return res;
    }
};