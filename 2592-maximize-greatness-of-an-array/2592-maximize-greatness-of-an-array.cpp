class Solution {
public:
    int maximizeGreatness(vector<int>& A) {
        sort(begin(A), end(A));
        multiset<int> ms(begin(A), end(A));
        int res = 0;
        for(auto& a : A) {
            auto it = ms.upper_bound(a);
            if(it == end(ms)) break;
            res++;
            ms.erase(it);
        }
        return res;
    }
};