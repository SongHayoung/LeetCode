class Solution {
public:
    int kthGrammar(int n, int k) {
        int len = 1<<(n-1);
        bool reverse = false;
        while(len != 1) {
            if(k > len / 2) {
                k = len - k + 1;
                if(!(n & 1))
                    reverse = !reverse;
            }
            len>>=1;
            n--;
        }
        return reverse;
    }
}; 