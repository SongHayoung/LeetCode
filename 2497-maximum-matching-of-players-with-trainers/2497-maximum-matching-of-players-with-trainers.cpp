class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        int res = 0;
        while(A.size() and B.size()) {
            if(A.back() <= B.back()) {
                res++;
                A.pop_back();
                B.pop_back();
            } else A.pop_back();
        }
        return res;
    }
};