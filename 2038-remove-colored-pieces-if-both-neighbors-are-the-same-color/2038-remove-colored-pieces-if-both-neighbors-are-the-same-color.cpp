class Solution {
public:
    bool winnerOfGame(string c) {
        int a = 0, b = 0;
        for(int i = 1; i < c.length() - 1; i++) {
            if(c[i] == c[i-1] and c[i] == c[i+1]) {
                a += c[i] == 'A';
                b += c[i] == 'B';
            }
        }
        return a > b;
    }
};