class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(begin(citations), end(citations));
        int papers = 0;
        for(int i = 1000; i >= 0; i--) {
            while(citations.size() and citations.back() == i) papers++, citations.pop_back();
            if(i <= papers) return i;
        }
        return 0;
    }
};