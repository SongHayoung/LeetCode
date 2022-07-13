class Solution {
    string convert(string s) {
        string odd = "", even = "";
        for(int i = 0; i < s.length(); i++) {
            if(i & 1) odd.push_back(s[i]);
            else even.push_back(s[i]);
        }
        sort(begin(odd), end(odd));
        sort(begin(even), end(even));
        return odd + even;
    }
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> us;
        for(auto& w : words) {
            us.insert(convert(w));
        }
        return us.size();
    }
};