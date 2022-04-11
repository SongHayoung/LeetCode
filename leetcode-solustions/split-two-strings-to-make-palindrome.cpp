class Solution {
    bool isPalindrome(string &s, int odd) {
        if((!(s.length() & 1) && odd != 0) || ((s.length() & 1) && odd != 1))
            return false;

        int start = 0, end = s.length() - 1;
        while(start < end) {
            if(s[start] != s[end]) return false;
            start++, end--;
        }
        return true;
    }
public:
    bool checkPalindromeFormation(string a, string b) {
        unordered_map<char, int> aMap, bMap;
        int len = a.length(), aOdd = 0, bOdd = 0;
        for(int i = 0; i < len; i++) {
            aMap[a[i]]++;
            bMap[b[i]]++;
        }
        for(auto entity : aMap) {
            if(entity.second & 1) aOdd++;
        }

        for(auto entity : bMap) {
            if(entity.second & 1) bOdd++;
        }

        if(isPalindrome(a, aOdd) || isPalindrome(b, bOdd)) return true;
        for(int i = 0; i < len; i++) {
            aOdd += aMap[a[i]] & 1 ? 1 : -1;
            aOdd += aMap[b[i]] & 1 ? 1 : -1;
            bOdd += bMap[a[i]] & 1 ? 1 : -1;
            bOdd += bMap[b[i]] & 1 ? 1 : -1;
            aMap[a[i]]--;
            bMap[b[i]]--;
            aMap[b[i]]++;
            bMap[a[i]]++;
            swap(a[i], b[i]);
            if(isPalindrome(a, aOdd) || isPalindrome(b, bOdd)) return true;
        }

        return false;
    }
};
