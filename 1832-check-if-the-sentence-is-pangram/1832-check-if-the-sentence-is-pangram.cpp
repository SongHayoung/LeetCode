class Solution {
public:
    bool checkIfPangram(string sentence) {
        const int pangram = (1<<26) - 1;
        int res = 0;
        for(auto& c : sentence) {
            res |= (1<<(c-'a'));
            if(!(res ^ pangram)) return true;
        }

        return !(pangram ^ res);
    }
};