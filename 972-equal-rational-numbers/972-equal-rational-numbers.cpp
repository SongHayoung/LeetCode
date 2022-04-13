class Parser {
private:
    string front;
    string back;

public:
    Parser(string s): front(s.substr(0, s.find('.'))) {
        const string fill = "00000000";
        auto dot = s.find('.');
        if(dot == string::npos) {
            back = fill;
        } else {
            auto sof = s.find('(');
            if(sof == string::npos) {
                back = (s.substr(dot + 1) + fill).substr(0,8);
            } else {
                string nrPart = s.substr(dot+1, sof-dot-1);
                auto eof = s.find(')');
                string rPart = s.substr(sof+1, eof-sof-1);
                back = nrPart;
                for(int i = 0; i < 8; i++) {
                    back += rPart;
                }
                back = back.substr(0,8);
            }
        }
    }

    bool eq(int f, int b, int of, int ob) {
        b = b + 1;
        if(b == 100000000) b = 0, f += 1;
        return b == ob and f == of;
    }

    bool eq(Parser* other) {
        if(this->front == other->front and this->back == other->back) return true;
        int b = stoi(back), ob = stoi(other->back);
        int f = stoi(front), of = stoi(other->front);

        return eq(f,b,of,ob) || eq(of,ob,f,b);
    }

    void print() {
        cout<<"["<<front<<" / "<<back<<"]"<<endl;
    }
};
class Solution {
public:
    bool isRationalEqual(string s, string t) {
        Parser* ss = new Parser(s);
        Parser* tt = new Parser(t);

        return ss->eq(tt);
    }
};