class Solution {
public:
    bool isCircularSentence(string A) {
        for(int i = 0; i < A.length(); i++) {

            if(i == A.length() - 1) {
                if(A[0] != A[i]) return false;
            }
            else if(A[i] == ' ') {
                if(i + 1 == A.length()) return false;
                if(A[i-1] != A[i+1]) return false;
            }
        }
        return true;
    }
};
