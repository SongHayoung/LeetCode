class Solution {
    bool ok(unordered_map<int,int>& freq, vector<int>& A, int p, int k, vector<int>& res) {
        if(p == A.size()) return true;
        if(freq[A[p]] == 0) return ok(freq,A,p+1,k,res);
        int cnt = freq[A[p]];
        if(freq.count(A[p] + 2 * k) and freq[A[p] + 2 * k] >= cnt) {
            freq[A[p]] -= cnt;
            freq[A[p] + 2 * k] -= cnt;
            for(int i = 0; i < cnt; i++) res.push_back(A[p] + k);
            if(ok(freq,A,p+1,k,res)) return true;
            freq[A[p]] += cnt;
            freq[A[p] + 2 * k] += cnt;
        }
        return false;
    }
public:
    vector<int> recoverArray(vector<int>& A) {
        vector<int> ks;
        sort(begin(A), end(A));
        {
            int n = A.size() / 2;
            unordered_map<int,int> freq;
            for(int i = 1, cnt = 0; cnt < n; i++, cnt++) {
                if(i != 1 and A[i] == A[i-1]) continue;
                int k = A[i] - A[0];
                if(k & 1 or !k) continue;
                freq[k/2]++;
            }
            for(int i = n * 2 - 2, cnt = 0; cnt < n; i--,cnt++) {
                if(i != n * 2 - 2 and A[i] == A[i+1]) continue;
                int k = A.back() - A[i];
                if(k & 1 or !k) continue;
                freq[k/2]++;
            }
            for(auto& [k,v] : freq) if(v == 2) ks.push_back(k);
        }
        unordered_map<int,int> freq;
        for(auto& a : A) freq[a]++;
        for(auto& k : ks) {
            vector<int> res;
            if(k and ok(freq,A,0,k,res)) {
                return res;
            }
        }
        return {-1};
    }
};