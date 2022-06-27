class Solution {
public:
    int minOperations(vector<int>& A) {
        unordered_map<int, int> freq;
        for(auto& a : A) if(a) freq[a]++;
        int res = 0;
        while(!freq.empty()) {
            unordered_map<int,int> nfreq;
            int mask = INT_MAX;
            for(auto& [u, v] : freq) {
                if(u & 1) {mask = 0;}
                else if(mask) {
                    int c = 0;
                    int v = u;
                    while(!(v & 1)) {
                        c++;
                        v>>=1;
                    }
                    mask = min(mask, c);
                }
            }
            res += mask;
            for(auto& [k,v] : freq) {
                int kk = k;
                if(mask) {
                    kk>>=mask;
                } else if(kk & 1) {
                    kk -= 1;
                    res += v;
                }
                if(kk) nfreq[kk] += v;
            }
            swap(freq, nfreq);
        }
        return res;
    }
};