
class Solution {
    long long mod = 1e9 + 7;
    vector<int> PHI(int N) {
        vector<int> primes; primes.reserve(N/10);
        vector<int> phi(N + 1);
        vector<int> lp(N+1,0);
        phi[1]=1;
        for (int i=2;i<=N;++i) {
            if (!lp[i]) { lp[i]=i; primes.push_back(i); phi[i]=i-1; }
            for (int p: primes) {
                long long v=1LL*i*p; if (v> N || p>lp[i]) break;
                lp[v]=p;
                if (i%p==0){ phi[v]=phi[i]*p; break; }
                else { phi[v]=phi[i]*(p-1); }
            }
        }
        return phi;
    }
    void divspf(int x, const vector<int>& spf, vector<int>& res) {
        vector<pair<int,int>> fac;
        while (x>1) {
            int p = spf[x], c=0;
            while (x%p==0){ x/=p; ++c; }
            fac.push_back({p,c});
        }
        res = {1};
        for (auto [p,c]: fac) {
            int sz = res.size();
            long long mul=1;
            for (int e=1;e<=c;++e){
                mul*=p;
                for (int i=0;i<sz;++i) res.push_back(int(res[i]*mul));
            }
        }
    }
public:
    int totalBeauty(vector<int>& nums) {
        int n = nums.size();
        int maxA = *max_element(nums.begin(), nums.end());
        int N = max(2, maxA);
        vector<int> spf(N+1);
        for (int i=2;i<=N;++i) if(!spf[i]){ for(long long j=i;j<=N;j+=i) if(!spf[j]) spf[j]=i; }
        vector<int> phi = PHI(N);
        vector<vector<int>> divs(n);
        vector<vector<int>> valsByD(N+1);
        
        vector<int> tmp;
        for (int i=0;i<n;++i){
            divspf(nums[i], spf, tmp);
            divs[i]=tmp;
            for(int d: tmp) valsByD[d].push_back(nums[i]);
        }
        for (int d=1; d<=N; ++d){
            sort(begin(valsByD[d]), end(valsByD[d]));
            valsByD[d].erase(unique(valsByD[d].begin(), valsByD[d].end()), valsByD[d].end());
        }
        vector<vector<int>> bit(N+1);
        for (int d=1; d<=N; ++d){
            if (!valsByD[d].empty()) bit[d].assign(int(valsByD[d].size()+1), 0);
        }
        auto bsum = [&](vector<int>& b, int idx){
            long long s=0;
            for (; idx>0; idx-=idx&-idx){ s+=b[idx]; if(s>=mod) s-=mod; }
            return int(s);
        };
        auto badd = [&](vector<int>& b, int idx, int val){
            for (int m=b.size()-1; idx<=m; idx+=idx&-idx){
                int t=b[idx]+val; if(t>=mod) t-=mod; b[idx]=t;
            }
        };
        long long res=0;
        for (int i=0;i<n;++i){
            int x=nums[i];
            for (int d: divs[i]){
                auto& coords = valsByD[d];
                int idx = int(lower_bound(coords.begin(), coords.end(), x) - coords.begin()) + 1;
                int s = bsum(bit[d], idx-1);
                long long cur = s + 1; if (cur>=mod) cur-=mod;
                res = (res + 1LL*phi[d]*cur) % mod;
                badd(bit[d], idx, cur);
            }
        }
        return res;
    }
};