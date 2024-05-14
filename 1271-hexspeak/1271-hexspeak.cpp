class Solution {
public:
    string toHexspeak(string num) {
        long long x = stoll(num);
        if(!x) return "O";
        unordered_map<int, char> mp;
        mp[1] = 'I';
        mp[0] = 'O';
        mp[10] = 'A';
        mp[11] = 'B';
        mp[12] = 'C';
        mp[13] = 'D';
        mp[14] = 'E';
        mp[15] = 'F';
        string res = "";
        while(x) {
            long long r = x % 16;
            x /= 16;
            if(!mp.count(r)) return "ERROR";
            res.push_back(mp[r]);
        }
        reverse(begin(res), end(res));
        return res;
    }
};