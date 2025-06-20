
class Solution {
    int helper(pair<int,int> A, pair<int, int> B, int k) {
        if(A.first > A.second) swap(A.first, A.second);
        if(B.first > B.second) swap(B.first, B.second);
        int mia = min(A.first, k);
        A.first -= mia, k -= mia;
        B.second += mia;
        int mib = min(B.first, k);
        B.first -= mib, k -= mib;
        A.second += mib;
        return A.second - A.first + B.second - B.first;
    }
public:
    int maxDistance(string s, int k) {
        pair<int,int> ns{0,0}, ew{0,0};
        int res = 0;
        for(auto& ch : s) {
            if(ch == 'N') ns.first++;
            if(ch == 'S') ns.second++;
            if(ch == 'E') ew.first++;
            if(ch == 'W') ew.second++;
            res = max(res, helper(ns,ew,k));
        }
        return res;
    }
};