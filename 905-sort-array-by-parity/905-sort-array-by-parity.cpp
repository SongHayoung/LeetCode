class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        sort(begin(A), end(A), [](int& a, int& b) {
           bool _a = a&1, _b = b&1;
            if(_a == _b) return a<b;
            return _b;
        });
        return A;
    }
};