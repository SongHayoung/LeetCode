class Solution {
public:
    long long makeSimilar(vector<int>& A, vector<int>& B) {
        vector<int> oa, ea, ob, eb;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] % 2) oa.push_back(A[i]);
            else ea.push_back(A[i]);
            
            if(B[i] % 2) ob.push_back(B[i]);
            else eb.push_back(B[i]);
        }
        sort(begin(oa), end(oa));
        sort(begin(ea), end(ea));
        sort(begin(ob), end(ob));
        sort(begin(eb), end(eb));
        long long res = 0;
        for(int i = 0; i < oa.size(); i++) {
            if(oa[i] < ob[i]) res += (ob[i] - oa[i]) / 2;
        }
        for(int i = 0; i < ea.size(); i++) {
            if(ea[i] < eb[i]) res += (eb[i] - ea[i]) / 2;
        }
        return res;
    }
};