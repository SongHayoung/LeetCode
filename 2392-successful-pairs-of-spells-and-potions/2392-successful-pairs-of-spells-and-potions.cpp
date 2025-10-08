class Solution {
public:
    vector<int> successfulPairs(vector<int>& A, vector<int>& B, long long success) {
        vector<int> res;
        sort(begin(B), end(B));
        for(auto& a : A) {
            long long req = success / a;
            if(req * a != success) req++;
            auto lb = end(B) - lower_bound(begin(B), end(B), req);
            res.push_back(lb);
        }
        return res;
    }
};