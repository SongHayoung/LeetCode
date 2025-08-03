

int freq[101010];
class Solution {
    pair<vector<int>,unordered_map<int,int>> compression(vector<int>& A) {
        set<int> ord;
        for(auto& a : A) ord.insert(a);
        unordered_map<int,int> o, ro;
        for(int id = 0; auto& val : ord) o[val] = id, ro[id++] = val;
        vector<int> res;
        for(auto& a : A) res.push_back(o[a]);
        return {res,ro};
    }
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        auto [A,ids] = compression(nums);
        int n = nums.size(), sq = sqrt(n), ma = 0;
        memset(freq,0,sizeof freq);
        vector<set<int>> ord(n + 1);
        auto add = [&](int x) {
            if(freq[x]) ord[freq[x]].erase(x);
            freq[x]++;
            if(ma < freq[x]) ma = freq[x];
            ord[freq[x]].insert(x);
        };
        auto del = [&](int x) {
            ord[freq[x]].erase(x);
            if(freq[x] == ma and ord[freq[x]].size() == 0) ma--;
            --freq[x];
            if(freq[x]) ord[freq[x]].insert(x);
        };
        auto qry = [&]() -> pair<int,int> {
            if(ma == 0) return {0,0};
            return {ma, *ord[ma].begin()};
        };
        vector<array<int,4>> Q;
        for(int i = 0; auto& q : queries) {
            int l = q[0], r = q[1], t = q[2];
            if(r - l + 1 >= t)
                Q.push_back({l,r,t,i++});
        }
        sort(begin(Q), end(Q), [&](auto& a, auto& b) {
            int asq = a[0] / sq, bsq = b[0] / sq;
            if(asq != bsq) return asq < bsq;
            return asq & 1 ? (a[1] > b[1]) : (a[1] < b[1]);
        });
        vector<int> res(queries.size(), -1);
        int le = 0, ri = 0;
        for(auto& [l,r,t,idx] : Q) {
            while(ri <= r) add(A[ri++]);
            while(le > l) add(A[--le]);
            
            while(ri > r + 1 and ma >= t) del(A[--ri]);
            while(le < l and ma >= t) del(A[le++]);

            if(ma < t) continue;
            auto [cnt,val] = qry();
            res[idx] = ids[val];
        }
        return res;
    }
};
