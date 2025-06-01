struct Seg {
    int mi, ma, lazy, best;
    Seg *left, *right;
    Seg(int l, int r) : mi(l), ma(r), lazy(0), best(0), left(nullptr), right(nullptr) {
        if(l ^ r) {
            int m = l + (r - l) / 2;
            left = new Seg(l,m);
            right = new Seg(m+1,r);
        }
    }
    void pushDown() {
        if(lazy) {
            best += lazy;
            if(left) left->lazy += lazy;
            if(right) right->lazy += lazy;
            lazy = 0;
        }
    }
    void update(int l, int r, int x) {
        pushDown();
        if(l <= mi and ma <= r) {
            lazy += x;
            pushDown();
            return;
        }
        if(l > ma or r < mi) return;
        left->update(l,r,x);
        right->update(l,r,x);
        best = max(left->best, right->best);
    }
};
class Solution {
    vector<bool> prime;
public:
    Solution() {
        prime = vector<bool>(101010, true);
        prime[0] = prime[1] = false;
        for(long long i = 2; i < prime.size(); i++) {
            if(!prime[i]) continue;
            for(long long j = i * i; j < prime.size(); j += i) prime[j] = false;
        }
    }
    vector<int> maximumCount(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int,set<int>> container;
        set<int> order;
        int n = nums.size();
        Seg* seg = new Seg(0, n - 1);
        auto ask = [&](int x) {
            if(!container.count(x)) return pair<int,int>{-1,-1};
            return pair<int,int>{*begin(container[x]), *prev(end(container[x]))};
        };
        auto push = [&](int idx) {
            if(!prime[nums[idx]]) return;
            container[nums[idx]].insert(idx);
        };
        auto pop = [&](int idx) {
            if(!prime[nums[idx]]) return;
            container[nums[idx]].erase(idx);
            if(container[nums[idx]].size() == 0) container.erase(nums[idx]);
        };
        auto update = [&](int l, int r, int op) {
            if(l != -1) seg->update(l,n-1,op);
            if(r != -1) seg->update(0,r-1,op);
        };

        for(int i = 0; i < n; i++) push(i);
        vector<int> res;
        for(auto& [k,v] : container) {
            auto [l,r] = ask(k);
            update(l,r,1);
        }
        for(auto& q : queries) {
            int idx = q[0], val = q[1];
            if(nums[idx] != val) {
                if(prime[nums[idx]]) {
                    auto [l1,r1] = ask(nums[idx]);
                    update(l1,r1,-1);
                    pop(idx);
                    auto [l2,r2] = ask(nums[idx]);
                    update(l2,r2,1);
                }
                nums[idx] = val;
                if(prime[nums[idx]]) {
                    auto [l1,r1] = ask(nums[idx]);
                    update(l1,r1,-1);
                    push(idx);
                    auto [l2,r2] = ask(nums[idx]);
                    update(l2,r2,1);
                }
            }
            res.push_back(seg->best);
        }
        return res;
    }
};
