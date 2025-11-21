using ull = unsigned long long;

struct RH {
    ull B1=146527ULL, B2=19260817ULL;
    vector<ull> h1,h2,p1,p2;
    RH() {}
    RH(const string& s){ build(s); }
    void build(const string& s){
        int n=s.size();
        h1.assign(n+1,0); h2.assign(n+1,0);
        p1.assign(n+1,1); p2.assign(n+1,1);
        for(int i=0;i<n;i++){
            h1[i+1]=h1[i]*B1+(ull)(s[i]-'a'+1);
            h2[i+1]=h2[i]*B2+(ull)(s[i]-'a'+1);
            p1[i+1]=p1[i]*B1;
            p2[i+1]=p2[i]*B2;
        }
    }
    pair<ull,ull> get(int l,int r) const {
        return {h1[r]-h1[l]*p1[r-l], h2[r]-h2[l]*p2[r-l]};
    }
};

struct Block {
    int which, l, len; // which: 0->s, 1->r
};

class Solution {
    string s, r;
    RH hs, hr;
    int n;

    inline char at(int which, int pos) const {
        return which==0 ? s[pos] : r[pos];
    }

    inline pair<ull,ull> hget(int which, int l, int r) const {
        return which==0 ? hs.get(l,r) : hr.get(l,r);
    }

    int lcpSub(int w1,int p1,int w2,int p2,int maxlen) const {
        int lo=0, hi=maxlen;
        while(lo<hi){
            int mid=(lo+hi+1)>>1;
            if(hget(w1,p1,p1+mid)==hget(w2,p2,p2+mid)) lo=mid;
            else hi=mid-1;
        }
        return lo;
    }

    bool lexLess(const array<Block,2>& A, const array<Block,2>& B) const {
        int i1=0,i2=0,off1=0,off2=0;
        while(i1<2 && i2<2){
            int rem1 = (i1<2? A[i1].len - off1 : 0);
            int rem2 = (i2<2? B[i2].len - off2 : 0);
            if(rem1==0){ i1++; off1=0; continue; }
            if(rem2==0){ i2++; off2=0; continue; }
            int l = lcpSub(A[i1].which, A[i1].l+off1, B[i2].which, B[i2].l+off2, min(rem1,rem2));
            if(l < min(rem1,rem2)){
                char c1 = at(A[i1].which, A[i1].l+off1+l);
                char c2 = at(B[i2].which, B[i2].l+off2+l);
                return c1 < c2;
            }
            if(rem1==rem2){ i1++; i2++; off1=off2=0; }
            else if(rem1<rem2){ i1++; off1=0; off2+=l; }
            else { i2++; off2=0; off1+=l; }
        }
        return false;
    }

public:
    string lexSmallest(string _s) {
        s=_s; n=s.size();
        if(n<=1) return s;
        r=s; reverse(r.begin(), r.end());
        hs.build(s); hr.build(r);

        array<Block,2> best = { Block{0,0,n}, Block{0,0,0} };

        for(int i=2;i<=n;i++){
            array<Block,2> pref = { Block{1,n-i,i}, Block{0,i,n-i} };
            if(lexLess(pref, best)) best = pref;
            array<Block,2> suf  = { Block{0,0,n-i}, Block{1,0,i} };
            if(lexLess(suf, best)) best = suf;
        }

        string res=s;
        if(best[0].which==0 && best[0].l==0 && best[0].len==n) return res;
        if(best[0].which==1){ int i = best[0].len; reverse(res.begin(), res.begin()+i); }
        else { int i = best[1].len; reverse(res.end()-i, res.end()); }
        return res;
    }
};