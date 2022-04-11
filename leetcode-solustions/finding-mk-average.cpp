class MKAverage {
private:
    multiset<int> less, mid, greater;
    int m;
    int k;
    list<int> l;
    long long sum = 0;
public:
    MKAverage(int m, int k) : m(m), k(k) {}

    void addElement(int num) {
        if(l.size() < m) mid.insert(num);
        l.push_back(num);
        if(l.size() == m) {
            for(int i = 0; i < k; i++) {
                less.insert(*mid.begin());
                greater.insert(*mid.rbegin());
                mid.erase(mid.begin());
                mid.erase(prev(mid.end()));
            }
            sum = accumulate(mid.begin(), mid.end(), 0L);
        } else if(l.size() > m) {
            if(less.find(l.front()) != less.end()) {
                less.erase(less.find(l.front()));
            } else if(greater.find(l.front()) != greater.end()) {
                greater.erase(greater.find(l.front()));
            } else {
                mid.erase(mid.find(l.front()));
                sum -= l.front();
            }
            if(!less.empty() && *less.rbegin() >= l.back()) {
                less.insert(l.back());
            } else if(!greater.empty() && *greater.begin() <= l.back()) {
                greater.insert(l.back());
            } else {
                mid.insert(l.back());
                sum += l.back();
            }
            while(less.size() < k) {
                less.insert(*mid.begin());
                sum -= *mid.begin();
                mid.erase(mid.begin());
            }
            while(less.size() > k) {
                mid.insert(*less.rbegin());
                sum += *less.rbegin();
                less.erase(prev(less.end()));
            }

            while(greater.size() < k) {
                greater.insert(*mid.rbegin());
                sum -= *mid.rbegin();
                mid.erase(prev(mid.end()));
            }
            while(greater.size() > k) {
                mid.insert(*greater.begin());
                sum += *greater.begin();
                greater.erase(greater.begin());
            }


            l.pop_front();
        }
    }

    int calculateMKAverage() {
        return l.size() != m ? -1 : sum / mid.size();
    }
};
