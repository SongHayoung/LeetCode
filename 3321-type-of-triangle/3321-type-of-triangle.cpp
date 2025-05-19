
class Solution {
public:
    string triangleType(vector<int>& A) {
        sort(begin(A), end(A));
        if(A[0] == A[2]) return "equilateral";
        if(A[0] + A[1] <= A[2]) return "none";
        if(A[0] == A[1]) return "isosceles";
        if(A[1] == A[2]) return "isosceles";
        return "scalene";
    }
};


