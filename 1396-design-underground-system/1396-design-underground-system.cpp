class UndergroundSystem {
private:
    map<pair<string, string>, pair<long, int>> avgTime;
    map<int, pair<string, int>> checkInMap;
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};

        return;
    }

    void checkOut(int id, string stationName, int t) {
        auto in = checkInMap[id];
        if(!avgTime.count({in.first, stationName})) {
            avgTime[{in.first, stationName}] = {0, 0};
        }
        avgTime[{in.first, stationName}].first += t  - in.second;
        avgTime[{in.first, stationName}].second += 1;

        return;
    }

    double getAverageTime(string startStation, string endStation) {
        return 1.0 * avgTime[{startStation, endStation}].first / avgTime[{startStation, endStation}].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */