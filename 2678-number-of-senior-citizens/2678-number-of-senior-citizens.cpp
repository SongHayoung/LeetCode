class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(auto d : details) {
            int age = (d[11] - '0') * 10 + d[12] - '0';
            res += age > 60;
        }
        return res;
    }
};
