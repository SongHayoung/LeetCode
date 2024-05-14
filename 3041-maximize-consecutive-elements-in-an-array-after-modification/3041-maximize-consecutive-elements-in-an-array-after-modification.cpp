class Solution {
public:
    int maxSelectedElements(vector<int>& A) {
        sort(begin(A), end(A));
        vector<array<int,3>> S;
        for(int i = 0; i < A.size();) {
            int j = i + 1, x = A[i];
            bool fl = false;
            while(j < A.size() and (A[j] == x or A[j] == x + 1)) {
                if(A[j] == x) fl = true;
                x = A[j++];
            }
            S.push_back({A[i],fl,x});
            i = j;
        }
        int res = 1;
        for(int i = 0; i < S.size();) {
            auto [l,fl,r] = S[i];
            if(A.back() + 1 - l + 1 <= res) break;
            int ri = r + 1, le = fl ? l : l + 1, add = 1, j = i + 1;
            bool ok = true;
            res = max(res, r - l + 1 + fl);
            while(j < S.size() and S[j][0] == ri + add and ok) {
                auto [_,ffl,rr] = S[j++];
                res = max(res, rr - le + ffl + 1);
                ok = ffl;
                ri = rr;
                add = 2;
            }
            i = max(i + 1, j - 1);
        }

        return res;
    }
};