class Solution {
public:
    int minProcessingTime(vector<int>& A, vector<int>& tasks) {
        sort(rbegin(tasks), rend(tasks));
        sort(begin(A), end(A));
        int res = 0;
        while(A.size()) {
            for(int i = 0; i < 4; i++) {
                int time = A.back() + tasks.back();
                res = max(res, time); tasks.pop_back();
            }
            A.pop_back();
        }
        return res;
    }
};