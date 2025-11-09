class Solution {
public:
    int countOperations(int num1, int num2) {
        int op = 0;
        if(num1 < num2) swap(num1, num2);
        while(num1 and num2) {
            op+= num1 / num2;
            num1 %= num2;
            if(num1 < num2) swap(num1, num2);
        }
        return op;
    }
};