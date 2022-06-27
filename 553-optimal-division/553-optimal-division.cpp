class Solution {
public:
    string optimalDivision(vector<int>& A) {
        string res = to_string(A[0]);
        if(A.size() == 1) return res;
        if(A.size() == 2) return res + "/" + to_string(A[1]);
        res += "/(";
        for(int i = 1; i < A.size(); i++) {
            res += to_string(A[i]);
            res.push_back('/');
        }
        res.back() = ')';
        return res;
    }
};