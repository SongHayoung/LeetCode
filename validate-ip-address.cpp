class Solution {
private:
    const string Neither = "Neither";
    const string IPv4 = "IPv4";
    const string IPv6 = "IPv6";
private:
    vector<string> getAddress(string IP, char symbol) {
        vector<string> res;
        size_t pos = 0, prevPos = 0;
        while((pos = IP.find(symbol, pos)) != std::string::npos) {
            res.push_back(IP.substr(prevPos, pos - prevPos));
            prevPos = ++pos;
        }
        res.push_back(IP.substr(prevPos));

        return res;
    }
    
    int charToDecimal(char c) {
        return '0' <= c && c <= '9' ? c & 0b1111 : INT_MIN;
    }

    int hexaToDecimal(char c) {
        switch (c) {
            case 'a':
            case 'A':
                return 10;
            case 'b':
            case 'B':
                return 11;
            case 'c':
            case 'C':
                return 12;
            case 'd':
            case 'D':
                return 13;
            case 'e':
            case 'E':
                return 14;
            case 'f':
            case 'F':
                return 15;
            default:
                return charToDecimal(c);
        }
    }
    
    string isIPv4(string IP) {
        vector<string> addresses = getAddress(IP, '.');

        if(addresses.size() != 4)
            return Neither;

        for(string address : addresses) {
            int val = 0;
            if(address.length() > 3 || address.length() < 1 || (address[0] == '0' && address != "0"))
                return Neither;

            for(int i = 0; i < address.length(); i++) {
                val = val * 10 + charToDecimal(address[i]);
                if(!(0 <= val && val <= 255))
                    return Neither;
            }
        }

        return IPv4;
    }

    string isIPv6(string IP) {
        vector<string> addresses = getAddress(IP, ':');

        if(addresses.size() != 8)
            return Neither;

        for(string address : addresses) {
            int val = 0;

            if(address.length() > 4 || address == "")
                return Neither;

            for(int i = 0; i < address.length(); i++) {
                val = val * 16 + hexaToDecimal(address[i]);
                if(!(0 <= val && val <= 65535))
                    return Neither;
            }
        }

        return IPv6;
    }
public:
    string validIPAddress(string IP) {
        return IP.length() <= 39 ? IP.find(".") != std::string::npos ? isIPv4(IP) : isIPv6(IP) : Neither;
    }
};
