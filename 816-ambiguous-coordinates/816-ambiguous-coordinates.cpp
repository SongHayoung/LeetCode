class Solution {
    vector<string> dnc(string s) {
        vector<string> res;
        deque<char> front, back(begin(s), end(s));
        unordered_map<char, int> mp;
        for(auto& ch : s) mp[ch]++;
        
        for(int i = 0; i < s.length(); i++) {
            front.push_back(back.front()); back.pop_front();
            mp[front.back()]--;
            if(front[0] == '0' and front.size() > 1) break;
            if(!back.empty() and mp['0'] == back.size()) continue;
            if(!back.empty() and back.back() == '0') continue;
            string f(begin(front), end(front));
            string b(begin(back), end(back));
            if(b.length() == 0) res.push_back(f);
            else res.push_back(f + "." + b);
        }
        return res;
    }
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        for(int i = 2; i < s.length() - 1; i++) {
            auto l = s.substr(1, i - 1), r = s.substr(i, s.length() - 1 - i);
            auto L = dnc(l), R = dnc(r);
            for(auto& ll : L) {
                for(auto& rr : R) {
                    res.push_back("(" + ll + ", " + rr +")");
                }
            }
        }
        return res;
    }
};