class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx >= sx and ty >= sy) {
            if(tx == sx and ty == sy) return true;
            if(ty == tx) return false;
            if(tx < ty) {
                int n = (ty - tx) / tx + 1;
                if(ty - n * tx >= sy) ty = ty - n * tx;
                else {
                    n = (ty - sy) / tx;
                    if(n == 0) return false;
                    ty = ty - n * tx;
                }
            } else {
                int n = (tx - ty) / ty + 1;
                if(tx - n * ty >= sx) tx = tx - n * ty;
                else {
                    n = (tx - sx) / ty;
                    if(n == 0) return false;
                    tx = tx - n * ty;
                } 
            }
        }
        return false;
    }
};