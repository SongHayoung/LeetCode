class NumberContainers {
    unordered_map<int, int> mp;
    unordered_map<int, set<int>> mmp;
public:
    NumberContainers() {}

    void change(int index, int number) {
        if(mp.count(index)) {
            mmp[mp[index]].erase(index);
        }
        mp[index] = number;
        mmp[number].insert(index);
    }

    int find(int number) {
        if(mmp[number].empty()) return -1;
        return *begin(mmp[number]);
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */