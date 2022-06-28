class Solution {
    bool possible(int count[26], int target) {
        for(int i = 0; i < target; i++) {
            if(!(count[i] ^ count[target])) return false;
        }
        return true;
    }
public:
    int minDeletions(string s) {
        int count[26]{};
        int res = 0;
        for(auto c : s) count[c - 'a']++;
        for(int i = 0; i < 26; i++) {
            while(count[i] && !possible(count, i)) count[i]--, res++;
        }

        return res;
    }
};