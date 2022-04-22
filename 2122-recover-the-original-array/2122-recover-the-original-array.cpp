class Solution {
    int getK(vector<int>& A, int i, int j) {
        int ak = A[i] - A[0], zk = A.back() - A[j];
        if(ak == zk and !(ak & 1))
            return ak / 2;
        return INT_MIN;
    }
    vector<int> kCand(vector<int>& A) {
        int sum = A[0] + A.back(); //A - k + Z + k
        int n = A.size();
        vector<pair<int,int>> cand;
        
        for(int i = 1; i < n; i++) { //find A + k + Z - k combinations
            auto j = lower_bound(begin(A), end(A), sum - A[i]) - begin(A);
            if(j < i) break;
            
            if(A[j] + A[i] == sum)
                cand.push_back({i,j});
        }
        unordered_set<int> res;
        for(auto [i, j] : cand) {
            int k1 = getK(A,i,j), k2 = getK(A,j,i);
            if(k1 != INT_MIN) res.insert(k1);
            if(k2 != INT_MIN) res.insert(k2);
        }
        
        return vector<int>(begin(res),end(res));
    }
    bool helper(vector<int>& A, unordered_map<int,int>& mp, int k, vector<int>& res, int p, int i) {
        if(p == A.size()) return true;
        if(mp[A[p]] == 0) return helper(A,mp,k,res,p+1,i);
        if(mp[A[p] + 2*k] == 0 or i == res.size()) return false;
        mp[A[p] + 2*k]--;
        mp[A[p]]--;
        res[i] = A[p] + k;
        
        if(helper(A,mp,k,res,p+1,i+1)) return true;

        mp[A[p] + 2*k]++;
        mp[A[p]]++;
        
        return false;
    }
public:
    vector<int> recoverArray(vector<int>& A) {
        sort(begin(A), end(A));
        if(A.size() == 2) return {(A[0] + A[1]) / 2};
        
        auto kc = kCand(A);
        int n = A.size();
        unordered_map<int, int> mp;
        for(auto& a : A) mp[a]++;
        
        vector<int> res(n/2);
        for(auto& k : kc)
            if(helper(A,mp,k,res,0,0)) {
                return res;
            }
        return {};
        
    }
};