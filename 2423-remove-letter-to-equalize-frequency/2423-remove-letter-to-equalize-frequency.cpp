class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char,int> freq;
        for(auto& ch : word) freq[ch]++;
        for(auto& [k,v] : freq) {
            --v;
            int ma = 0, ok = true;
            for(auto& [k,v] : freq) {
                if(ma == 0) ma = v;
                else if(v and ma != v) ok = false;
            }
            if(ok) return true;
            v++;
        }
        return false;
    }
};