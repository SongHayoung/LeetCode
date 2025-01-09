class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for(auto w : words) {
            if(w.length() < pref.length()) continue;
            bool find = true;
            for(int i = 0; i < pref.length() and find; i++) {
                if(w[i] != pref[i]) find = false;
            }
            if(find) res++;
        }
        return res;
    }
};