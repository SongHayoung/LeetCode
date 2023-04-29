class Solution {
    long long  fenwick[101010];
    map<int, int> range;
    void merge(int n) {
        range[n] = n;
        auto ub = range.upper_bound(n);
        if(ub != end(range) and ub->first == n + 1) {
            range[n] = ub->second;
            range.erase(ub);
        }
        auto it = range.lower_bound(n);
        if(it != begin(range) and prev(it)->second + 1 == n) {
            prev(it)->second = it->second;
            range.erase(it);
        }
    }
    long long next(int p, int n) {
        auto it = range.upper_bound(p);
        --it;
        if(it->second == n) {
            auto iit = range.lower_bound(1);
            if(iit->first == 1) return iit->second + 1;
            return 1;
        }
        return it->second + 1;
    }
    void update(int n, int k) {
        while(n < 101010) {
            fenwick[n] += k;
            n += n & -n;
        }
    }
    long long query(int n) {
        long long res = 0;
        while(n) {
            res += fenwick[n];
            n -= n & -n;
        }
        return res;
    }
    long long distance(long long a, long long b, long long n) {
        if(a == b) return 0;
        if(a < b) return b - a - (query(b) - query(a));
        return n - a - (query(n) - query(a)) + b - query(b);
    }
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        long long res = 0, at = 1;
        range.clear();
        memset(fenwick,0,sizeof fenwick);
        map<int,set<int>> seq;
        for(int i = 0; i < nums.size(); i++) {
            seq[nums[i]].insert(i+1);
        }
        auto nextOf = [&](long long p) {
            auto it = begin(seq);
            auto iit = it->second.lower_bound(p);
            if(iit != end(it->second)) return *iit;
            return *it->second.begin();
        };
        while(seq.size()) {
            auto it = begin(seq);
            if(it->second.size() == 0) seq.erase(it);
            else {
                auto p = nextOf(at);
                res += distance(at,p,nums.size());
                seq.begin()->second.erase(p);
                update(p,1);
                merge(p);
                at = next(p,nums.size());
                res += 1;
            }
        }
        return res;
    }
};
