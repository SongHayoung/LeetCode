class Solution {
public:
    int numTeams(vector<int>& r) {
        set<int> left(begin(r), next(begin(r))), right(next(begin(r)), end(r));
        int res(0), sz = r.size();
        for(int i = 1; i < sz - 1; i++) {
            right.erase(r[i]);
            int leftGreater = distance(left.lower_bound(r[i]), end(left)), rightGreater = distance(right.lower_bound(r[i]), end(right)), leftLess = left.size() - leftGreater, rightLess = right.size() - rightGreater;
            res += leftGreater * rightLess + leftLess * rightGreater;
            left.insert(r[i]);
        }
        return res;
    }
};