class Solution {
    bool isP(unsigned long long llp) {
        string p = to_string(llp);
        int l = 0, r = p.length() -1;
        while(l <= r) {
            if(p[l] != p[r]) return false;
            l++; r--;
        }
        return true;
    }
    unordered_set<unsigned long long> makePalindromes() {
        unordered_set<unsigned long long> prefix = {1,2}, temp = prefix, res = {1,2,3};
        for(int i = 0; i < 4; i++) {
            unordered_set<unsigned long long> nTemp;
            for(auto& tmp : temp) {
                nTemp.insert(tmp * 10);
                prefix.insert(tmp * 10);
                nTemp.insert(tmp * 10 + 1);
                prefix.insert(tmp * 10 + 1);
                nTemp.insert(tmp * 10 + 2);
                prefix.insert(tmp * 10 + 2);
            }
            swap(temp, nTemp);
        }
        
    
        
        for(auto& p : prefix) {
            string l = to_string(p);
            string r = l; reverse(r.begin(), r.end());
            res.insert(stoll(l + r));
            res.insert(stoll(l + '0' + r));
            res.insert(stoll(l + '1' + r));
            res.insert(stoll(l + '2' + r));
        }
        return res;
    }
public:
    int superpalindromesInRange(string left, string right) {
        unordered_set<unsigned long long> palindromes = makePalindromes();
        
        unsigned long long L = stoll(left), R = stoll(right);
        int res = 0;
        
        for(auto& p : palindromes) {
            unsigned long long superP = p * p;
            if(L <= superP and superP <= R and isP(superP)) {
                ++res;
            }

        }
        return res;
    }
};