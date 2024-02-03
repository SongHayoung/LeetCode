/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 * public:
 *     InfiniteStream(vector<int> bits);
 *     int next();
 * };
 */
vector<int> pi(vector<int>& p) {
    vector<int> PI(p.size());
    for(int i = 1, j = 0; i < p.size(); i++) {
        while(j and p[i] != p[j]) j = PI[j-1];
        if(p[i] == p[j]) PI[i] = ++j;
    }
    return PI;
}
class Solution {
public:
    int findPattern(InfiniteStream* stream, vector<int>& pattern) {
        vector<int> PI = pi(pattern);
        for(int i = 0, j = 0; ; i++) {
            int now = stream->next();
            while(j and now != pattern[j]) j = PI[j-1];
            if(now == pattern[j]) {
                if(++j == pattern.size()) {
                    return i - pattern.size() + 1;
                }
            }
        }
        return -1;
    }
};