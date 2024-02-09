class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        int g = deck.size();
        for(int i = 0; i < deck.size(); i++) {
            freq[deck[i]]++;
        }
        for(auto& [k,v] : freq) {
            g = __gcd(g,v);
        }
        return g != 1;
    }
};