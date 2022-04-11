
class PhoneDirectory {
    unordered_set<int> released;
    int ma;
    int mi;
public:
    PhoneDirectory(int maxNumbers):ma(maxNumbers), mi(0) {
    }

    int get() {
        if(!released.empty()) {
            int n = *released.begin();
            released.erase(released.begin());
            return n;
        } else {
            if(mi == ma) return -1;
            return mi++;
        }
    }

    bool check(int number) {
        if(number >= mi) return true;
        return released.count(number);
    }

    void release(int number) {
        if(number < mi)
            released.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */