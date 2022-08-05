class Solution {
public:
    int wateringPlants(vector<int>& A, int capacity) {
        int res = 0, now = capacity;
        for(int i = 0; i < A.size(); i++) {
            res += 1;
            if(now < A[i]) {
                res += 2 * i;
                now = capacity;
            }
            now -= A[i];
        }
        return res;
    }
};