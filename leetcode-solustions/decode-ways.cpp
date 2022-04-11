private:
    unordered_map<string, int> strings;
private:
    bool canDecoded(int digit) {
        return 1 <= digit && digit <= 26;
    }

    int recursive(string plain) {
        if(plain.length() == 0) {
            return 1;
        }

        auto stringValue = strings.find(plain);
        if(stringValue != strings.end()) {
            return stringValue->second;
        }

        int ret = 0;
        for(int i = 1; i <= 2; i++) {
            if(plain.length() >= i && plain[0] != '0' && canDecoded(stoi(plain.substr(0,i)))) {
                ret += recursive(plain.substr(i));
            }
        }
        strings[plain] = ret;
        return ret;
    }
public:
    int numDecodings(string s) {
        return recursive(s);
    }
};
