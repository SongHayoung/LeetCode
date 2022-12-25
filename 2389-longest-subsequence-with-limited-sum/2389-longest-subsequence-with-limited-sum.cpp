class Solution {
public:
    vector<int> answerQueries(vector<int>& A, vector<int>& Q) {
        sort(begin(A), end(A));
        vector<long long> psum {0};
        for(auto& a : A) psum.push_back(psum.back() + a);
        vector<int> res;
        for(auto& q : Q) {
            auto now = upper_bound(begin(psum),end(psum), q) - begin(psum);
            res.push_back(now - 1);
        }
        return res;
    }
};