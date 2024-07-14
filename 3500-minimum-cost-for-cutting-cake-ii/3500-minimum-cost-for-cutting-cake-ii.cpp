
class Solution {
public:
    long long minimumCost(int n, int m, vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        long long res = 0, opa = 1, opb = 1;
        while(A.size() and B.size()) {
            if(A.back() > B.back()) {
                res += A.back() * opb;
                opa++;
                A.pop_back();
            } else {
                res += B.back() * opa;
                opb++;
                B.pop_back();
            }
        }
        return res + accumulate(begin(A), end(A),0ll) * opb + accumulate(begin(B), end(B),0ll) * opa;
    }
};
