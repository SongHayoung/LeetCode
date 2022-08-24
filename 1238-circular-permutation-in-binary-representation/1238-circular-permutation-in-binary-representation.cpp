class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        deque<int> res {0};
        int p = 1;
        while(res.size() < (1<<n)) {
            int sz = res.size();
            for(int i = sz - 1; i >= 0; i--) {
                res.push_back(res[i] | p);
            }
            p<<=1;
        }
        while(res.front() != start) {
            res.push_back(res.front());
            res.pop_front();
        }
        return vector<int>(begin(res), end(res));
    }
};