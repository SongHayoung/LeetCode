
class Spreadsheet {
    map<pair<int,int>,int> cells;
    pair<int,int> parse(string cell) {
        int row = 0, col = cell[0] - 'A';
        for(int i = 1; i < cell.size(); i++) row = row * 10 + cell[i] - '0';
        return {row,col};
    }
public:
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) {
        cells[parse(cell)] = value;
    }

    void resetCell(string cell) {
        cells.erase(parse(cell));
    }

    int getValue(string formula) {
        string c1 = "", c2 = "";
        while(formula.back() != '+') {
            c2.push_back(formula.back());
            formula.pop_back();
        }
        formula.pop_back();
        while(formula.back() != '=') {
            c1.push_back(formula.back());
            formula.pop_back();
        }
        reverse(begin(c1), end(c1));
        reverse(begin(c2), end(c2));
        int res = 0;
        if(isdigit(c1[0])) {
            res += stoi(c1);
        } else res += cells[parse(c1)];

        if(isdigit(c2[0])) {
            res += stoi(c2);
        } else res += cells[parse(c2)];

        return res;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */