class Solution {
public:
    long long minimumTotalCost(vector<int>& A, vector<int>& B) {
        {
            unordered_map<int,int> freq;
            for(int i = 0; i < A.size(); i++) {
                if(++freq[A[i]] > A.size()) return -1;
                if(++freq[B[i]] > A.size()) return -1;
            }
        }
        int n = A.size();
        vector<int> fl(n);
        vector<int> at;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            if(A[i] == B[i]) {
                fl[i] = true;
                at.push_back(i);
                mp[A[i]]++;
            }
        }
        if(at.size() == 0) return 0;
        int ma = 0;
        for(auto& [k,v] : mp) {
            ma = max(ma, v);
        }
        long long res = accumulate(begin(at), end(at), 0ll);
        if(ma * 2 <= at.size()) {
            return res;
        }
        int cnt = ma - (at.size() - ma);
        int x = 0;
        for(auto& [k,v] : mp) if(v == ma) x = k;
        for(int i = 0; i < fl.size() and cnt; i++) {
            if(fl[i]) continue;
            if(A[i] == x or B[i] == x) continue;
            cnt--;
            res += i;
        }
        return cnt ? -1 : res;
    }
};