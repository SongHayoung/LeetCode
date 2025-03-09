
struct Seg {
    int mi,ma,best;
    Seg *left, *right;
    Seg(vector<int>& A, int l, int r) : mi(A[l]), ma(A[r]), best(INT_MAX), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
        }
    }
    void add(int x, int idx) {
        if(mi <= x and x <= ma) {
            best = min(best, idx);
            if(left) left->add(x,idx);
            if(right) right->add(x,idx);
        }
    }
    void remove(int x) {
        if(mi <= x and x <= ma) {
            best = INT_MAX;
            if(left and right) {
                right->remove(x);
                left->remove(x);
                best = min(left->best, right->best);
            }
        }
    }
    int query(int x) {
        if(mi >= x) return best;
        if(ma < x) return INT_MAX;
        return min(left->query(x), right->query(x));
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<int> S = baskets;
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        Seg* seg = new Seg(S,0,S.size() - 1);
        unordered_map<int,deque<int>> mp;
        for(int i = 0; auto& b : baskets) mp[b].push_back(i++);
        for(auto& [k,v] : mp) seg->add(k,v[0]);
        int res = 0;
        for(auto& f : fruits) {
            int idx = seg->query(f);
            if(idx == INT_MAX) res++;
            else {
                seg->remove(baskets[idx]);
                int cap = baskets[idx];
                mp[cap].pop_front();
                if(mp[cap].size()) seg->add(cap, mp[cap][0]);
            }
        }
        return res;
    }
};