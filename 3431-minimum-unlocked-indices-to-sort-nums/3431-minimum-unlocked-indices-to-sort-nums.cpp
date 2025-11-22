
struct FW {
    vector<long long> fw;
    int siz;
    FW(int n) : siz(n + 1) {
        fw = vector<long long>(siz);
    }
    void update(int n, int x) {
        n += 1;
        while(n < siz) {
            fw[n] += x;
            n += n & -n;
        }
    }
    long long query(int n) {
        n += 1;
        long long res = 0;
        while(n > 0) {
            res += fw[n];
            n -= n & -n;
        }
        return res;
    }
};
class Solution {
public:
    int minUnlockedIndices(vector<int>& nums, vector<int>& locked) {
        int n = nums.size();
        FW lo(n + 1), on(n + 1);
        map<int,deque<int>> at;
        set<int> los;
        for(int i = 0; i < n; i++) {
            at[nums[i]].push_back(i);
            if(locked[i]) {
                lo.update(i,1);
                los.insert(i);
            }
        }
        vector<int> S = nums;
        sort(begin(S), end(S));
        int res = 0, processed = 0;
        auto cleanLock = [&]() {
            while(los.size() and *begin(los) < processed) {
                lo.update(*begin(los), -1);
                los.erase(*begin(los));
            }
        };
        while(at.size()) {
            deque<deque<int>> dq;
            int lookup = begin(at)->first;
            while(at.count(lookup)) {
                dq.push_back(at[lookup]);
                at.erase(lookup);
                lookup++;
            }
            while(dq.size() >= 2) {
                bool shouldSwap = false;
                while(dq[0].size()) {
                    int at = dq[0].front(); dq[0].pop_front();
                    on.update(at, 1);
                    processed++;
                    while(dq[1].size() and dq[1][0] < at) {
                        on.update(dq[1][0], 1);
                        processed++;
                        dq[1].pop_front();
                        shouldSwap = true;
                    }
                    if(on.query(at) != at + 1) return -1;
                    if(shouldSwap) {
                        res += lo.query(at - 1);

                    }
                    while(los.size() and *begin(los) <= at - shouldSwap) {
                        lo.update(*begin(los), -1);
                        los.erase(*begin(los));
                    }
                }
                dq.pop_front();
                cleanLock();
            }
            while(dq[0].size()) {
                int at = dq[0][0]; dq[0].pop_front();
                on.update(at, 1);
                processed++;
            }
            cleanLock();

            if(on.query(processed - 1) != processed) return -1;
        }
        return res;
    }
};