class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0, b = 0;
        for(auto& ch : s) {
            if(ch == '1') b++;
            else res += b;
        }
        return res;
    }
};