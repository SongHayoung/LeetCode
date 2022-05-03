class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(begin(s1), end(s1));
        sort(begin(s2), end(s2));
        int compare = 0;
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] == s2[i]) continue;
            if(s1[i] > s2[i]) {
                if(compare == 0) compare = 1;
                else if(compare == -1) return false;
            } else {
                if(compare == 0) compare = -1;
                else if(compare == 1) return false;
            }
        }
        return true;
    }
};