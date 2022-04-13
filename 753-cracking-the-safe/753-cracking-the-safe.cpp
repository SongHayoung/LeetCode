class Solution {
    unordered_set<int> visited;
    int makeKey(string& str, int n) {
        int res = 0;
        for(int i = str.length() - n + 1; i < str.length(); i++) {
            res = res * 10 + (str[i] & 0b1111);
        }
        return res;
    }
    bool backTracking(string& res, int& ma, int n, int k) {
        if(visited.size() == ma) return true;
        int key = makeKey(res, n);
        for(int i = 0; i < k; i++) {
            if(visited.count(key * 10 + i)) continue;
            res += (i | 0b110000);
            visited.insert(key * 10 + i);
            if(backTracking(res, ma, n, k)) return true;
            res.pop_back();
            visited.erase(key * 10 + i);
        }
        return false;
    }
public:
    string crackSafe(int n, int k) {
        string res = string(n,'0');
        visited.insert(0);
        int ma = pow(k,n);
        backTracking(res,ma,n,k);
        return res;
    }
};