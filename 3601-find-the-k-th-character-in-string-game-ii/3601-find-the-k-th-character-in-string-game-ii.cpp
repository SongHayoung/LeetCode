class Solution {
    int helper(vector<int>& op, long long pos, long long& k) {
        long long len = 1ll<<pos;
        if(len >= k) return 0;
        int res = helper(op,pos + 1,k);
        if(len < k) {
            k -= len;
            res = (res + op[pos]) % 26;
        }
        return res;
    }
public:
    char kthCharacter(long long k, vector<int>& operations) {
        return 'a' + helper(operations,0,k);
    }
};