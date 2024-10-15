class FirstUnique {
    unordered_map<int, int> mp;
    queue<int> q;
public:
    FirstUnique(vector<int>& nums) {
        for(auto& n : nums) mp[n]++;
        for(auto& n : nums) {
            if(mp[n] == 1) q.push(n);
        }
    }

    int showFirstUnique() {
        while(!q.empty() and mp[q.front()] >= 2) q.pop();
        return q.empty() ? -1 : q.front();
    }

    void add(int value) {
        mp[value]++;
        if(mp[value] >= 2) return;
        q.push(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */