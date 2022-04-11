class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0, sz = citations.size(), res;
        while(end(citations) - lower_bound(begin(citations), end(citations), h) >= h) {
              res = h++;
        }
        return res;
    }
};