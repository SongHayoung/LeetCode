class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long res = 1;
        while(neededApples > 0) {
            long long now = ((res * 2 + 1) * (res * 2) / 2 - (res - 1) * (res) / 2 ) * 2 - res;
            now = now * 4 - res * 2 * 4;
            neededApples -= now;
            res++;
        }
        return (res-1) * 8;
    }
};