class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto w : words) {
            int i = 0, j = w.length() - 1;
            bool ok = true;
            while(i < j and ok) {
                if(w[i] != w[j]) ok = false;
                i += 1, j -= 1;
            }
            if(ok) return w;
        }
        return "";
    }
};