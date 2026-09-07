class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> freq;
    for(auto& w : words) freq[w]++;
    int k = words[0].length();
    int n = s.length(), tot = k * words.size();
    vector<int> res;
    for(int start = 0; start < k and start < n; start++) {
        unordered_map<string, int> window;
        deque<string> dq;
        int cnt = 0;
        for(int i = start; i < n; i += k) {
            int j = i + k;
            if(j > n) break;
            if(dq.size() == words.size()) {
                string del = dq[0]; dq.pop_front();
                if(freq.count(del) and window[del] == freq[del]) cnt--;
                --window[del];
                if(window[del] == 0) {
                    window.erase(del);
                }
            }
            string sub = s.substr(i,k);
            ++window[sub];
            if(freq.count(sub) and window[sub] == freq[sub]) cnt++;
            dq.push_back(sub);
            if(cnt == freq.size()) {
                res.push_back(j - tot);
            }
        }
    }
    return res;
    }
};