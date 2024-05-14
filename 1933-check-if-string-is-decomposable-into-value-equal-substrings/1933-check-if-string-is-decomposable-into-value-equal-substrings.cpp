class Solution {
public:
    bool isDecomposable(string s) {
        deque<int> cnt;
        for(int i = 0; i < s.length(); i++) {
            if(i and s[i] == s[i-1]) cnt.back()++;
            else cnt.push_back(1);
        }
        while(cnt.size() and cnt.back() % 3 == 0) cnt.pop_back();
        while(cnt.size() and cnt.front() % 3 == 0) cnt.pop_front();
        return cnt.size() == 1 and cnt[0] >= 2 and (cnt[0] - 2) % 3 == 0;
    }
};