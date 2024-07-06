class Solution {
public:
    long long countSubarrays(vector<int>& A, int k) {
        long long res = 0;
        vector<array<int,3>> B;
        for(int i = 0; i < A.size(); i++) {
            vector<array<int,3>> C;
            auto add = [&](int x, int l, int r) {
                if((x & k) != k) return;
                if(C.size() and C.back()[0] == x) {
                    C.back()[2] = r;
                } else C.push_back({x,l,r});
                if(x == k) res += (r - l + 1);
            };
            for(auto& [val,l,r] : B) add(A[i] & val, l, r);
            add(A[i],i,i);
            swap(B,C);
        }
        return res;
    }
};