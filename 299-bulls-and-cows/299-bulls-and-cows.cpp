class Solution {
public:
    string getHint(string secret, string guess) {
        int counter[10]{0,};
        int A = 0, B = 0;
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] == guess[i]) A++;
            else counter[secret[i] & 0b1111]++;
        }
        
        for(int i = 0; i < guess.length(); i++) {
            if(secret[i] == guess[i]) continue;
            if(counter[guess[i] & 0b1111]) {
                B++;
                counter[guess[i] & 0b1111]--;
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};