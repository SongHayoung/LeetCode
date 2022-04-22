class MajorityChecker {
    vector<pair<int,vector<int>>> index;
public:
    MajorityChecker(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
        for(auto &p : mp) {
            index.push_back({p.first, p.second});
        }
        sort(index.begin(), index.end(), [](auto& i1, auto& i2) {
            return i1.second.size() > i2.second.size();
        });
    }
    
    int query(int left, int right, int threshold) {
        for(auto &p : index) {
            if(p.second.size() < threshold) break;
            auto f = lower_bound(begin(p.second), end(p.second), left);
            auto t = upper_bound(begin(p.second), end(p.second), right);
            if(t - f >= threshold) {
                return p.first;
            }
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */