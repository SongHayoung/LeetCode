class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0;
        int n = 0, sz = seats.size();
        for(int i = 0; i < sz; i++) {
            if(seats[i] == 1) {
                seats[n++] = i;
            }
        }
        
        res = max(seats[0], sz - 1 - seats[n-1]);
        for(int i = 0; i < n - 1; i++) {
            res = max(res, (seats[i + 1] - seats[i]) / 2);
        }
        return res;
    }
};