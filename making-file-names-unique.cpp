class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> namesMap;
        for(int i = 0; i < names.size(); i++) {
            if(!namesMap.count(names[i])) {
                namesMap[names[i]]++;
            } else {
                for(int seq = namesMap[names[i]]; seq <= INT_MAX; seq++) {
                    string isExists = names[i] + "(" + to_string(seq) + ")";
                    if(namesMap.find(isExists) == namesMap.end()) {
                        namesMap[isExists]++;
                        namesMap[names[i]] = seq;
                        names[i] = isExists;
                        break;
                    }
                }

            }
        }

        return names;
    }
};
