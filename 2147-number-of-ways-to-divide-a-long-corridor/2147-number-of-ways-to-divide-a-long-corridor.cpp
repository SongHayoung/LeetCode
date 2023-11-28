class Solution {
    int mod = 1e9 + 7;
public:
    int numberOfWays(string corridor) {
        int n = corridor.length(), seat = 0, counter = 0, totalSeat = 0;
        unsigned long long res = 1;
        for(int i = 0; i < n; i++) {
            if(corridor[i] == 'S') {
                seat++;
                totalSeat++;
            }
            if(seat == 2) {
                counter++;
            } else if(seat > 2) {
                res = (res * counter) % mod;
                counter = 0;
                seat = 1;
            }
        }
        return totalSeat == 0 or totalSeat & 1 ? 0 : res;
    }
};