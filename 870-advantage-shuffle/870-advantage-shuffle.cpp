class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s(A.begin(), A.end());
        vector<int> res(A.size(), -1);
        for(int i = 0; i < A.size(); i++) {
            auto it = s.upper_bound(B[i]);
            if(it == s.end()) continue;
            res[i] = *it;
            s.erase(it);
        }
        
        for(int i = 0; i < A.size(); i++) {
            if(res[i] == -1) {
                res[i] = *s.rbegin();
                s.erase(prev(s.end()));
            }
        }

        return res;
    }
};