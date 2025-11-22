class Solution {
public:
    long long modeWeight(vector<int>& nums, int k) {
        long long res = 0, best = 0;
        unordered_map<int, set<int>> ord;
        unordered_map<int, int> freq;
        auto add = [&](int x) {
            if(freq[x]) ord[freq[x]].erase(x);
            ++freq[x];
            ord[freq[x]].insert(x);
            if(freq[x] > best) best = freq[x];
        };
        auto del = [&](int x) {
            ord[freq[x]].erase(x);
            if(ord[freq[x]].size() == 0) {
                ord.erase(freq[x]);
                if(best == freq[x]) best--;
            }
            --freq[x];
            if(freq[x]) ord[freq[x]].insert(x);
        };
        auto qry = [&]() {
            return best * *begin(ord[best]);
        };
        for(int i = 0; i < nums.size(); i++) {
            add(nums[i]);
            if(i >= k) del(nums[i-k]);
            if(i + 1 >= k) res += qry();
        }
        return res;
    }
};