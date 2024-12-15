class Solution {
    int helper(vector<int>& f, int target, int best) {
        int res = INT_MAX;
        unordered_map<int,int> dp{{0,0}};
        for(int i = 0; i < f.size(); i++) {
            unordered_map<int,int> dpp;
            auto apply = [&](int key, int val) {
                assert(0 <= key and key <= target);
                if(key + val >= best) return;
                if(!dpp.count(key)) dpp[key] = INT_MAX;
                dpp[key] = min(dpp[key], val);
            };
            for(auto& [k,v] : dp) {
                if(f[i] >= target) {
                    unordered_set<int> use{min(target, k), 0};
                    for(auto& u : use) {
                        int x = f[i] - (target - u);
                        int plus = max(0, x - target);
                        apply(min(x,target), k + v + plus);
                    }
                } else if(f[i] + k >= target) {
                    unordered_set<int> use{min(target, k), target - f[i]};
                    for(auto& u : use) {
                        int x = f[i] - (target - u);
                        int plus = max(0, x - target);
                        apply(min(x,target), k + v + plus);
                    }
                    apply(f[i], v + k);
                } else {
                    int req = target - f[i] - k;
                    apply(0, k + v + req);
                    apply(f[i], k + v);
                }
            }
            swap(dp, dpp);
        }
        for(auto& [k,v] : dp) res = min(res, k + v);
        return res;
    }
public:
    int makeStringGood(string s) {
        vector<int> freq(26);
        for(auto& ch : s) freq[ch-'a']++;
        int positiveMin = INT_MAX;
        for(auto& f : freq) if(f) positiveMin = min(positiveMin, f);
        int start = s.length(), threshold = s.length() / (26 - count(begin(freq), end(freq),0)) - 2 * positiveMin;
        while(freq.size() and freq.back() == 0) freq.pop_back();
        for(int i = 0; i < freq.size(); i++) {
            if(freq[i] and freq[i] >= threshold) start = min(start, freq[i]);
        }
        int ma = *max_element(begin(freq), end(freq));
        int res = s.length() - ma;
        for(int i = start; i <= ma; i++) {
            res = min(res, helper(freq,i,res));
        }
        return res;
    }
};