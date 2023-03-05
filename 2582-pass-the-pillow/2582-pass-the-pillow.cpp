class Solution {
public:
    int passThePillow(int n, int time) {
        int dir = 0;
        while(time >= (n - 1)) {
            time -= (n - 1);
            dir = !dir;
        }
        int res = dir ? n : 1;
        if(dir) res -= time;
        else res += time;
        return res;
    }
};
