
class RideSharingSystem {
    deque<int> drivers, riders;
    unordered_set<int> cancel;
    unordered_set<int> has;
public:
    RideSharingSystem() {

    }

    void addRider(int riderId) {
        riders.push_back(riderId);
        has.insert(riderId);
    }

    void addDriver(int driverId) {
        drivers.push_back(driverId);
    }

    vector<int> matchDriverWithRider() {
        while(riders.size() and cancel.count(riders[0])) {
            cancel.erase(riders[0]);
            riders.pop_front();
        }
        if(drivers.size() == 0 or riders.size() == 0) return {-1,-1};
        vector<int> res{drivers[0], riders[0]};
        drivers.pop_front();
        riders.pop_front();
        has.erase(res[1]);
        return res;
    }

    void cancelRider(int riderId) {
        if(has.count(riderId)) cancel.insert(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */

