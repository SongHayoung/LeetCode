class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int res = 0, n = arrivals.size();
        unordered_map<int,int> freq;
        vector<bool> discarded(n);
        for(int day = 0; day < n; day++) {
            if(day >= w and !discarded[day-w]) {
                // remove stale inventory
                --freq[arrivals[day-w]];
                assert(freq[arrivals[day-w]] >= 0);
            }
            ++freq[arrivals[day]];
            if(freq[arrivals[day]] > m) {
                // remove latest item and increase discard day
                --freq[arrivals[day]];
                discarded[day] = true;
                assert(freq[arrivals[day]] == m);
                res++;
            }
        }
        return res;
    }
};