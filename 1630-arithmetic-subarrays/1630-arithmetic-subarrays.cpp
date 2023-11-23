class Solution {
    bool qry(vector<int>& num, int l, int r) {
        unordered_set<int> s;
        int mi = INT_MAX, ma = INT_MIN;
        for(int i = l; i <= r; i++) {
            s.insert(num[i]);
            mi = min(mi, num[i]);
            ma = max(ma, num[i]);
        }
        
        if((ma - mi) % (r - l)) return false;
        
        int diff = (ma - mi) / (r - l);
        if(diff == 0) return s.size() == 1;
        if(diff and s.size() != (r - l + 1)) return false;
        int base = mi;
        while(base <= ma) {
            if(!s.count(base)) return false;
            base += diff;
        }
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {    
        int n = nums.size(), m = l.size();
        
        vector<bool> res(m);
        for(int i = 0; i < m; i++) {
            res[i] = qry(nums,l[i],r[i]);
        }
        return res;
    }
};