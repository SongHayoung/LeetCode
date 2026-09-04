class Solution {
public:
    string trafficSignal(int timer) {
        return !timer ? "Green" : timer == 30 ? "Orange" : 30 < timer and timer <= 90 ? "Red" : "Invalid";
    }
};