class Solution {
public:
    int countKConstraintSubstrings(string& s, int k) {
        deque<int> A{-1}, B{-1};
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') {
                A.push_back(i);
                while(A.size() - 1 > k) A.pop_front();
            }
            else {
                B.push_back(i);
                while(B.size() - 1 > k) B.pop_front();
            }
            res += i - min(A[0],B[0]);
        }
        return res;
    }
};
