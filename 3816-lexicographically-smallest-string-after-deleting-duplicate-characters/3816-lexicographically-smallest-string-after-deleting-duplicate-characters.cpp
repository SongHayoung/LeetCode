class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        unordered_map<char,int> freq;
        for(auto& ch : s) freq[ch]++;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            string ss = "";
            for(auto& now : s) {
                while(ss.size() and ss.back() > now and freq[ss.back()] >= 2) {
                    freq[ss.back()]--;
                    ss.pop_back();
                }
                ss.push_back(now);
            }
            swap(ss,s);
        }
        while(s.size() and freq[s.back()] >= 2) {
            freq[s.back()]--;
            s.pop_back();
        }
        return s;
    }
};
