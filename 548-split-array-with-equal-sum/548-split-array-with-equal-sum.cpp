class Solution {
public:
    bool splitArray(vector<int>& A) {
        int n = A.size();
        vector<int> psum(n + 1, 0);
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[psum[i+1] = psum[i] + A[i]].push_back(i);
        }
        
        unordered_set<int> vis[n+1][2];
        
        for(int i = 1; i < n; i++) {
            int sum = psum[i];
            if(i + 1 > n) continue;
            for(auto& j : mp[psum[i+1] + sum]) {
                if(j + 2 > n or j <= i) continue;
                if(vis[j][0].count(sum)) continue;
                
                vis[j][0].insert(sum);
                for(auto& k : mp[psum[j+2] + sum]) {
                    if(k + 2 > n or k <= j + 1) continue;
                    if(vis[k][1].count(sum)) continue;
                    
                    vis[k][1].insert(sum);
                    if(n - 1 <= k + 1) continue;
                    if(psum.back() == psum[k+2] + sum)
                        return true;
                }
            }
        }
        return false;
    }
};