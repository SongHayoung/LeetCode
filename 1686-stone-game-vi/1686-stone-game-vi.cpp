class Solution {
public:
    int stoneGameVI(vector<int>& A, vector<int>& B) {
        vector<array<int,3>> stone;
        for(int i = 0; i < A.size(); i++) {
            stone.push_back({A[i] + B[i], A[i], B[i]});
        }
        sort(rbegin(stone), rend(stone));
        int a = accumulate(begin(A), end(A), 0), b = accumulate(begin(B), end(B), 0);
        for(int i = 0; i < stone.size(); i++) {
            auto [s, al, bo] = stone[i];
            if(i & 1) a -= al;
            else b -= bo;
        }
        return a == b ? 0 : a > b ? 1 : -1;
    }
};