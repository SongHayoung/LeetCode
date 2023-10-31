class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        for(int i = 0, now = 0; i < pref.size(); i++) {
            int n = pref[i] ^ now;
            pref[i] = n;
            now ^= pref[i];
        }
        return pref;
    }
};