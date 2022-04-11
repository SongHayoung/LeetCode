struct Data {
    string name;
    int time;
    int amount;
    string city;
    bool isPushed;

    std::string toString() {
        return name + "," + to_string(time) + "," + to_string(amount) + "," + city;
    }
};

bool cmp(const Data &d1, const Data &d2) {
    return d1.time < d2.time;
}

class Solution {
private:
    Data getData(string &str) {
        Data res;
        stringstream ss;
        int cnt = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ',') {
                switch (cnt) {
                    case 0:
                        res.name = ss.str();
                        break;
                    case 1:
                        res.time = stoi(ss.str());
                        break;
                    case 2:
                        res.amount = stoi(ss.str());
                        res.city = str.substr(i + 1);
                        break;
                }
                cnt++;
                ss.str("");
            } else {
                ss << str[i];
            }
        }
        res.isPushed = false;

        return res;
    }

public:
    vector<string> invalidTransactions(vector<string> &transactions) {
        vector<string> res;
        map<string, vector<Data>> myMap;
        for (int i = 0; i < transactions.size(); i++) {
            Data data = getData(transactions[i]);
            myMap[data.name].push_back(data);
        }

        for (auto it = myMap.begin(); it != myMap.end(); it++) {
            sort(it->second.begin(), it->second.end(), cmp);
            for (int i = it->second.size() - 1, j = i - 1; i >= 0; --i) {
                bool flag = false;
                for (; j >= 0 && it->second[i].time - it->second[j].time <= 60; --j) {
                    if (it->second[j].city != it->second[i].city) {
                        if (!it->second[j].isPushed) {
                            res.push_back(it->second[j].toString());
                            it->second[j].isPushed = true;
                        }
                        flag = true;
                    }
                }
                if (!it->second[i].isPushed && (flag || it->second[i].amount > 1000)) {
                    res.push_back(it->second[i].toString());
                    it->second[i].isPushed = true;
                }
            }
        }

        return res;
    }
};
