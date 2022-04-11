class LogSystem {
    string parseMin(string time, string g) {
        if(g == "Year")
            return time.substr(0,5) + "00:00:00:00:00";
        if(g == "Month")
            return time.substr(0,8) + "00:00:00:00";
        if(g == "Day")
            return time.substr(0,11) + "00:00:00";
        if(g == "Hour")
            return time.substr(0,14) + "00:00";
        if(g == "Minute")
            return time.substr(0,17) + "00";
        return time;
    }

    string parseMax(string time, string g) {
        if(g == "Year")
            return time.substr(0,5) + "12:31:23:59:59";
        if(g == "Month")
            return time.substr(0,8) + "31:23:59:59";
        if(g == "Day")
            return time.substr(0,11) + "23:59:59";
        if(g == "Hour")
            return time.substr(0,14) + "59:59";
        if(g == "Minute")
            return time.substr(0,17) + "59";
        return time;
    }
public:
    LogSystem() {}
    map<string, int> logs;
    
    void put(int id, string timestamp) {
        logs[timestamp] = id;
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        string st = parseMin(start, granularity), ed = parseMax(end, granularity);
        auto be = logs.lower_bound(st);
        auto fin = logs.upper_bound(ed);
        vector<int> res;
        for(; be != fin; be++) {
            res.push_back(be->second);
        }
        return res;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */