class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int now = 0, next, res = 0;
        for(auto& b : bank) {
            next = accumulate(begin(b), end(b), 0, [](int sum, char ch){ return sum + (ch == '1');});
            if(next) {
                res += now * next;
                now = next;
            }
        }
        return res;
    }
};