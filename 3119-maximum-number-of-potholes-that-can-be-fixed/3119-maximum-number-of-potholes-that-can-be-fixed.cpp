class Solution {
public:
    int maxPotholes(string road, int budget) {
        vector<int> s;
        for(int i = 0, cnt = 0; i <= road.size(); i++) {
            if(i == road.size() or road[i] == '.') {
                if(cnt) s.push_back(cnt);
                cnt = 0;
            } else cnt++;
        }
        sort(begin(s), end(s));
        int res = 0, skip = 0;
        while(s.size() and budget) {
            if(budget >= s.back() + 1) {
                res += s.back();
                budget -= (s.back() + 1);
            } else {
                res += budget - 1;
                budget = 0;
            }
            s.pop_back();
        }
        return res;
    }
};