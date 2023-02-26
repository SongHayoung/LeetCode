class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& A) {
        sort(begin(A), end(A));
        multiset<int> free, match;
        for(auto a : A) free.insert(a);
        int res = 0;
        for(int i = A.size() - 1; i >= 0; i--) {
            if(free.size() and A[i] * 2 <= *prev(end(free))) {
                free.erase(prev(end(free)));
                free.erase(free.find(A[i]));
                match.insert(A[i]);
                res += 2;
            } else if(match.size() and A[i] * 2 <= *prev(end(match))) {
                free.insert(*prev(end(match)));
                match.erase(prev(end(match)));
                free.erase(free.find(A[i]));
                match.insert(A[i]);
            }
        }
        return res;
    }
};