class SnapshotArray {
    int snapShot;
    unordered_map<int, vector<pair<int, int>>> ml;
public:
    SnapshotArray(int length) : snapShot(0) {    }

    void set(int index, int val) {
        if(ml[index].empty() || ml[index].back().first < snapShot)
            ml[index].push_back({snapShot, val});
        else
            ml[index].back().second = val;
    }

    int snap() {
        return snapShot++;
    }

    int get(int index, int snap_id) {
        auto it = upper_bound(ml[index].begin(), ml[index].end(), pair<int, int>(snap_id, INT_MAX));
        return it == ml[index].begin() ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */