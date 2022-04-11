class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        unordered_map<int, int> masks;
        for(int i = 0; i < words.size(); i++) {
            int mask = 0;
            for(auto ch : words[i]) {
                mask |= 1<<(ch-'a');
            }
            masks[mask] = max(masks[mask],(int)words[i].length());
        }
        for(auto [mask1, len1]: masks) {
            for(auto [mask2, len2]: masks) {
                if(!(mask1 & mask2))
                    res = max(res, len1 * len2);
            }
        }
        return res;
    }
};