#define all(a) begin(a), end(a)
class Solution {
    vector<int> extractSubsetOf(vector<int>& A, int k) {
        vector<int> res;
        unordered_map<int,int> mp;
        for(auto& n : A) mp[n]++;
        int n = A.size();
        int i = k >= 0 ? n - 1 : 0;
        bool self = false;
        while(0 <= i and i < n) {
            if(mp[A[i]]) {
                if(A[i] == k) self = true;
                if(!mp[A[i]-k]) return {INT_MIN};
                mp[A[i]-k]--;
                mp[A[i]]--;
                res.push_back(A[i]-k);
            }
            i += (k >= 0? -1 : 1);
        }
        if(!self) return {INT_MIN};
        sort(all(res));
        return res;
    }
    bool expectSubset(vector<int>& subset) {
        if(subset.size() & 1) {
            if(subset.size() > 1) return false;
            return subset[0] == 0;
        }
        return true;
    }
    bool helper(vector<int> A, vector<int>& res, int p) {
        if(p == res.size()) return true;
        int n = A.size();
        int gap = A[n-1] - A[n-2];
        
        auto poSubset = extractSubsetOf(A, gap);
        if(expectSubset(poSubset) and helper(poSubset, res, p + 1)) {
            res[p] = gap;
            return true;
        }
        
        auto neSubset = extractSubsetOf(A, -gap);
        if(expectSubset(neSubset) and helper(neSubset, res, p + 1)) {
            res[p] = -gap;
            return true;
        }
        
        return false;
    }
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(all(sums));
        vector<int> res(n);
        helper(sums, res, 0);
        return res;
    }
};