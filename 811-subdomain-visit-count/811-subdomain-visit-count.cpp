struct Domain {
    int visit;
    string domain;
    vector<int> pos;
};

class Solution {
    unordered_map<string, int> counts;

    Domain parse(string& s) {
        string v, domain, tmp;
        vector<int> pos{0};
        stringstream ss(s);
        getline(ss, v, ' ');
        while(getline(ss, tmp, '.')) {
            domain += tmp + '.';
            pos.push_back(domain.length());
        }
        domain.pop_back();
        pos.pop_back();
        

        return Domain {.visit = atoi(v.c_str()), .domain = domain, .pos = pos};
    }
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        for(auto& cpdomain: cpdomains) {
            Domain d = parse(cpdomain);
            for(auto& p : d.pos) {
                counts[&d.domain[p]] += d.visit;
            }
        }
        transform(counts.begin(), counts.end(), back_inserter(res), [] (pair<const string, int>& p) {
            return to_string(p.second) + ' ' + p.first;
        });
        return res;
    }
};