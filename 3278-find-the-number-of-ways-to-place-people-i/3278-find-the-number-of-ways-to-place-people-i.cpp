class Solution {
public:
    int numberOfPairs(vector<vector<int>>& A) {
        map<int,vector<int>> mp;
        sort(begin(A), end(A), [](auto a, auto b) {
            return a[1] < b[1];
        });
        for(auto& a : A) {
            mp[-a[0]].push_back(a[1]);
        }
        int res = 0;
        for(auto it = begin(mp); it != end(mp); it++) {
            vector<int>& vec1 = it->second;
            for(int j = vec1.size() - 1; j >= 0; j--) {
                int ri = j + 1 == vec1.size() ? INT_MAX : vec1[j+1];
                if(ri != INT_MAX) res++;
                for(auto jt = next(it); jt != end(mp); jt++) {
                    vector<int>& vec2 = jt->second;
                    bool ok = false;
                    for(int k = vec2.size() - 1; k >= 0 and vec2[k] >= vec1[j]; k--) {
                        if(vec2[k] < ri) {
                            ri = vec2[k];
                            if(!ok) {
                                ok = true;
                                res++;
                            }
                        }
                    }
                }
            }
        }
        
        
        
        return res;
    }
};