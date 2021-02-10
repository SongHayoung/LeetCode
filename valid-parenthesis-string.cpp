class Solution {
public:
    bool checkValidString(string s) {
        list<char> myList;
        auto iterator = myList.rbegin();
        for(int i = 0; i < s.length(); i++) {
            switch(s[i]) {
                case ')' : {
                    if (myList.empty())
                        return false;
                    iterator = myList.rbegin();
                    while (iterator != myList.rend() && *iterator != '(') {
                        iterator = next(iterator);
                    }
                    myList.erase(iterator == myList.rend() ? --myList.end() : --iterator.base());
                }
                break;
                default: myList.push_back(s[i]); break;
            }
        }

        iterator = myList.rbegin();
        int star = 0;
        while(iterator != myList.rend()) {
            switch (*iterator) {
                case '*' : star++; break;
                case '(' :
                    if(star) --star;
                    else return false;
            }
            ++iterator;
        }
        return true;
    }
};
