class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& R, vector<vector<int>>& q) {
        vector<array<int,3>> Q;
        for(int i = 0; i < q.size(); i++) {
            Q.push_back({q[i][1], q[i][0], i});
        }
        sort(begin(Q), end(Q));
        sort(begin(R), end(R), [](vector<int>& a, vector<int>& b) {return a[1] < b[1];});
        
        vector<int> res(Q.size());
        set<int> id;
        for(int i = Q.size() - 1, j = R.size() - 1; i >= 0; i--) {
            auto [msz, pref, qid] = Q[i];
            while(j >= 0 and R[j][1] >= msz) id.insert(R[j--][0]);
            
            if(id.empty()) res[qid] = -1;
            else {
                int gap = INT_MAX, pick = -1;
                auto it = id.lower_bound(pref);
                if(it != end(id))
                    gap = *it - pref, pick = *it;
                if(it != begin(id)) {
                    it = prev(it);
                    if(gap >= pref - *it)
                        pick = *it;
                }
                
                res[qid] = pick;
            }
        }
        
        return res;
    }
};