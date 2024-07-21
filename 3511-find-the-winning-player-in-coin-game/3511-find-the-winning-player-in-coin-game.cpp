class Solution {
public:
    string losingPlayer(int x, int y) {
        bool res = true;
        while(x >= 1 and y >= 4) {
            x -= 1, y -= 4;
            res = !res;
        }
        return res ? "Bob" : "Alice";
    }
};
