class Solution {
public:
    string largestMerge(string A, string B) {
        if(A.empty() or B.empty()) return A+B;
        return A > B ? A[0] + largestMerge(A.substr(1), B) : B[0] + largestMerge(A,B.substr(1));
    }
};