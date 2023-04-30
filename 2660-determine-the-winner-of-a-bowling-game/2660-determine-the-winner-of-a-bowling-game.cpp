class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int a = 0, b = 0;
        int fl1 = 1, fl2 = 1;
        for(int i = 0; i < player1.size(); i++) {
            if((i and player1[i-1] == 10) or (i >= 2 and player1[i-2] == 10)) a += player1[i] *2 ;
            else a += player1[i];
        }
        for(int i = 0; i < player2.size(); i++) {
            if((i and player2[i-1] == 10) or (i >= 2 and player2[i-2] == 10)) b += player2[i] * 2;
            else b += player2[i];
        }
        return a > b ? 1 : a < b ? 2 : 0;
    }
};