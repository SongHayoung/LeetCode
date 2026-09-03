class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int res = 0, at = 0;
        for(int x : requests) {
            res += abs(at - x);
            at = x;
        }
        return res;
    }
};