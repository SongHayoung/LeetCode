struct Helper {
    long long lim, sum;
    unordered_map<long long, long long> freq;
    set<pair<long long, long long>> hi, lo;
    Helper(long long k) : lim(k), sum(0) {}

    void remove(long long x) {
        if(freq[x]) {
            if(hi.count({freq[x], x})) {
                hi.erase({freq[x], x});
                sum -= freq[x] * x;
            } else lo.erase({freq[x], x});
        }
    }

    void insert(long long f, long long x) {
        sum += f * x;
        hi.insert({f,x});
    }
    void balance() {
        while(hi.size() > lim) {
            auto [ff,xx] = *hi.begin(); hi.erase(begin(hi));
            sum -= ff * xx;
            lo.insert({ff,xx});
        }
        while(hi.size() < lim and lo.size()) {
            auto [ff,xx] = *prev(end(lo)); lo.erase(prev(end(lo)));
            sum += ff * xx;
            hi.insert({ff,xx});
        }
        while(hi.size() and lo.size() and *hi.begin() < *prev(lo.end())) {
            auto [f1,x1] = *hi.begin(); hi.erase(begin(hi));
            auto [f2,x2] = *prev(end(lo)); lo.erase(prev(end(lo)));
            sum = sum - f1 * x1 + f2 * x2;
            hi.insert({f2,x2});
            lo.insert({f1,x1});
        }
    }
    void add(long long x) {
        remove(x);
        insert(++freq[x], x);
        balance();
    }
    void del(long long x) {
        remove(x);
        if(--freq[x]) {
            insert(freq[x], x);
        }
        balance();
    }
    long long query() {
        return sum;
    }
};
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        Helper* h = new Helper(x);
        vector<long long> res;
        for(int i = 0; i < nums.size(); i++) {
            h->add(nums[i]);
            if(i >= k) {
                h->del(nums[i-k]);
            }
            if(i + 1 >= k) {
                res.push_back(h->query());
            }
        }
        return res;
    }
};
