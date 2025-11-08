class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n <= 1) return n;
        int b = 0;
        while((1<<b) <= n) b++;

        return (1<<b) - 1 - minimumOneBitOperations(n ^ (1<<(b-1)));
    }
};