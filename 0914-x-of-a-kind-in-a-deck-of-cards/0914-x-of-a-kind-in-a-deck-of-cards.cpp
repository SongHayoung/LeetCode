class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        unordered_set<int> us;
        for(int i = 0; i < deck.size(); i++) {
            freq[deck[i]]++;
            if(deck.size() % (i + 1) == 0 and i) us.insert(i+1);
        }
        for(auto& [k,v] : freq) {
            unordered_set<int> uus;
            for(auto x : us) {
                if(v % x == 0) uus.insert(x);
            }
            swap(us,uus);
        }
        return us.size();
    }
};