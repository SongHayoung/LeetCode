class Solution {
    string parse(string& email) {
        bool meetPlus = false;
        stringstream ss;
        for(int i = 0; i < email.length(); i++) {
            if(email[i] == '.') continue;
            else if(email[i] == '+') meetPlus = true;
            else if(email[i] == '@') return ss.str() + email.substr(i);
            else if(!meetPlus) ss<<email[i];
        }
        
        return "";
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> validEmails;
        for(auto email : emails) {
            validEmails.insert(parse(email));
        }
        return validEmails.size();
    }
};