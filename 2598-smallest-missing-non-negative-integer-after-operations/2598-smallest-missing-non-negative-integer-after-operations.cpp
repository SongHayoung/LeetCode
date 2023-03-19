
class Solution {
public:
    int findSmallestInteger(vector<int>& A, int value) {
        int res = 0;
        unordered_map<int, int> x;
        for(auto a : A)  {
            if(a >= 0) x[a%value] += 1;
            else {
                a %= value;
                x[(a + value)  % value]+=1;
            }
        }
        while(x[res % value]) {
            x[res%value] -= 1;
            res += 1;
        }
        return res;
    }
};
