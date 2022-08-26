class Solution {
    bool match(int l, int r, int end, vector<int>& A) {
        int len1 = r - l, len2 = A.size() - 1 - end;
        if(len1 < len2) return false;
        int p = A.size() - 1;
        while(p >= end) if(A[r--] != A[p--]) return false;
        while(r >= l) if(A[r--] == 1) return false;
        return true;
    }
    vector<int> zfunction(vector<int>& now) {
        int l = 0, r = 0, n = now.size();
        vector<int> z(n);
        for(int i = 1; i < n; i++) {
            if(i > r) {
                l = r = i;
                while(r < n and now[r-l] == now[r]) r++;
                z[i] = r - l;
                r--;   
            } else {
                int k = i - l;
                if(z[k] < r - i + 1) z[i] = z[k];
                else {
                    l = i;
                    while(r < n and now[r-l] == now[r]) r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int cnt = count(begin(A), end(A), 1);
        if(cnt == 0) return {0,(int)A.size() - 1};
        if(cnt % 3) return {-1,-1};
        int cut = 0;
        for(int i = 0; i < A.size() and A[i] == 0; i++) cut += 1;
        vector<int> now;
        for(int i = cut; i < A.size(); i++) now.push_back(A[i]);
        
        int n = now.size();
        vector<int> z = zfunction(now);
        
        int padding = 0;
        for(int i = n - 1; now[i] == 0; i--) padding++;
        
        for(int i = n - 1, req = 1; i >= 0; i--,req++) {
            if(z[i] != req) continue;
            
            int j;
            for(j = i - 1; j >= req and now[j] == 0; j--) {}
            j += padding;
            if(j >= i) continue;
            
            if(j == req - 1) return {-1,-1};
            
            if(match(req,j,i,now)) return {cut + req - 1, cut + j + 1};
            
            req += (i - j - 1);
            i = j + 1;
            
        }
        return {-1,-1};
    }
};