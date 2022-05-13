class SnapshotArray {
    vector<vector<pair<int,int>>> snaps;
    int snapId = 0;
public:
    SnapshotArray(int length) {
        snaps = vector<vector<pair<int,int>>>(length, vector<pair<int,int>>(1,{0,0}));
    }
    
    void set(int index, int val) {
        if(snaps[index].back().first != snapId)
            snaps[index].push_back({snapId, -1});
        snaps[index].back().second = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto& his = snaps[index];
        auto it = upper_bound(begin(his),end(his), make_pair(snap_id,INT_MAX));
        if(it == begin(his)) return 0;
        --it;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */