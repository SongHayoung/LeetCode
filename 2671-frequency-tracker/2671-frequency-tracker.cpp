
class FrequencyTracker {
    unordered_map<int, int> freq;
    unordered_map<int, int> rfreq;
public:
    FrequencyTracker() {
        
    }

    void add(int number) {
        rfreq[freq[number]] -= 1;
        freq[number] += 1;
        rfreq[freq[number]] += 1;
    }

    void deleteOne(int number) {
        if(freq[number] == 0) return;
        rfreq[freq[number]] -= 1;
        freq[number] -= 1;
        rfreq[freq[number]] += 1;
    }

    bool hasFrequency(int frequency) {
        if(frequency == 0) return true;
        return rfreq[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */