class Solution {
public:
    string minimizeResult(string exp) {
        auto p = exp.find('+');
        string A = exp.substr(0,p), B = exp.substr(p+1);
        string res = "("+exp+")";
        long long val = stoll(A) + stoll(B);
        for(int i = 0; i < A.length(); i++) {
            for(int j = 1; j <= B.length(); j++) {
                string amul = A.substr(0,i), aplus = A.substr(i);
                string bplus = B.substr(0,j), bmul = B.substr(j);
                
                long long now = (amul == "" ? 1 : stoll(amul)) * (stoll(aplus) + stoll(bplus)) * (bmul == "" ? 1 : stoll(bmul));
                if(val > now) {
                    res = amul + "(" + aplus + "+" + bplus + ")" + bmul;
                    val = now;
                }
            }
        }
        return res;
    }
};