class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int binary = 0;
        int bitwiseAND = (1<<k) - 1;
        for(int i = 0; i < k; binary = ((binary << 1) | (s[i++] & 0b1111)));
        unordered_set<int> binarySet {binary};
        for(int i = k; i <= s.length(); binary = ((binary<<1) & bitwiseAND) | (s[i++] & 0b1111)) {
            binarySet.insert(binary);
        }

        return binarySet.size() == bitwiseAND + 1;
    }
};
