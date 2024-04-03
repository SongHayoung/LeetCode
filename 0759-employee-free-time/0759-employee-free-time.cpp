/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> A) {
        vector<Interval> res;
        int mi = INT_MAX;
        unordered_set<int> us;
        for(int i = 0; i < A.size(); i++) {
            reverse(begin(A[i]), end(A[i]));
            us.insert(i);
            mi = min(mi, A[i].back().start);
        }
        while(us.size()) {
            bool ok = false;
            unordered_set<int> exc;
            for(auto& u : us) {
                while(A[u].size() and A[u].back().start <= mi) {
                    mi = max(mi, A[u].back().end); A[u].pop_back();
                    ok = true;
                }
                if(A[u].size() == 0)  exc.insert(u);
            }
            for(auto& x : exc) us.erase(x);
            if(!ok and us.size()) {
                int nmi = INT_MAX;
                for(auto& u : us) {
                    nmi = min(nmi, A[u].back().start);
                }
                res.push_back(Interval(mi,nmi));
                mi = nmi;
            }
        }
        return res;
        
    }
};