class Logger {
    unordered_map<string, int> cache;
public:
    Logger() {}

    bool shouldPrintMessage(int timestamp, string message) {
        if(cache.count(message)) {
            if(cache[message] <= timestamp) {
                cache[message] = timestamp + 10;
                return true;
            }
            return false;
        } else {
            cache[message] = timestamp + 10;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */