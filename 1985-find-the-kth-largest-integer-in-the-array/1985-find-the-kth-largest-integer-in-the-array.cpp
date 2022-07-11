class Solution {
public:
    string kthLargestNumber(vector<string>& A, int k) {
        sort(begin(A), end(A), [](auto a, auto b) {
            if(a.length() == b.length()) return a > b;
            return a.length() > b.length();
        });
        return A[k-1];
    }
};