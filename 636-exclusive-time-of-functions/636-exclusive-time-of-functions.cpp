class Solution {
    struct log{
        int function;
        string status;
        int time;
    };
    vector<int> res;
    const char COLON = ':';
    const string START = "start";
    const string END = "end";
    log convert(string& str) {
        stringstream ss(str);
        string function, status, time;
        getline(ss, function, COLON);
        getline(ss, status, COLON);
        getline(ss, time, COLON);
        return {stoi(function), status, stoi(time)};
    }
    int calc(vector<string>& logs, int& i, int time) {
        int minus(0);
        log lg;
        for(; i < logs.size(); i++) {
            lg = convert(logs[i]);
            if(lg.status == START) {
                minus += calc(logs, ++i, lg.time);
            } else {
                res[lg.function] += lg.time - time + 1 - minus;
                return lg.time - time + 1;
            }
        }
        return lg.time - time + 1;
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        res = vector<int>(n);
        int i, minus(0), t;
        log lg;
        for(i = 0; i < logs.size(); i++) {
            lg = convert(logs[i]);
            if(lg.status == START) {
                t = lg.time;
                minus += calc(logs, ++i, lg.time);
            } else {
                res[lg.function] += lg.time - t + 1 - minus; minus = 0;
            }
        }
        return res;
    }
};