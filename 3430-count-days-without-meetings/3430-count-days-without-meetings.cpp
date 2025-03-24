class Solution {
public:
    int countDays(int days, vector<vector<int>>& A) {
        sort(rbegin(A), rend(A));
        while(A.size()) {
            int s = A.back()[0], e = A.back()[1];
            while(A.size() and A.back()[0] <= e + 1) {
                e = max(e, A.back()[1]);
                A.pop_back();
            }
            days -= (e - s + 1);
        }
        return days;
    }
};
