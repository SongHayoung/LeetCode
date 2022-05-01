struct Cell {
    int val;
    vector<Cell*> child;
    Cell(int val) :val(val) {}
    Cell(vector<Cell*> c):val(0), child(c){}
    void change(vector<Cell*> c) {
        child = c;
    }
    void change(int v) {
        val = v;
        child.clear();
    }
    int get() {
        if(child.empty())
            return val;
        int res = 0;
        for(auto& c : child) {
            res += c->get();
        }
        return res;
    }
};
class Excel {
    vector<vector<Cell*>> matrix;
    pair<int,int> parseSingle(string s) {
        int w = s[0] - 'A';
        int h = stoi(s.substr(1));
        return {h, w};
    }
public:
    Excel(int height, char width) {
        matrix = vector<vector<Cell*>>(27,vector<Cell*>(27, NULL));
        for(int i = 0; i < 27; i++)
            for(int j = 0; j < 27; j++)
                matrix[i][j] = new Cell(0);
    }
    
    void set(int row, char column, int val) {
        int h = row, w = column - 'A';
        if(matrix[h][w] == NULL) {
            matrix[h][w] = new Cell(val);
        } else {
            matrix[h][w]->change(val);
        }
    }
    
    int get(int row, char column) {
        int h = row, w = column - 'A';
        return matrix[h][w]->get();
    }
    
    int sum(int row, char column, vector<string> numbers) {
        int h = row, w = column - 'A';
        vector<Cell*> cells;
        for(auto& n : numbers) {
            if(n.find(':') == string::npos) {
                auto [r, c] = parseSingle(n);
                cells.push_back(matrix[r][c]);
            } else {
                auto [r1, c1] = parseSingle(n.substr(0, n.find(':')));
                auto [r2, c2] = parseSingle(n.substr(n.find(':') + 1));
                for(int i = r1; i <= r2; i++) {
                    for(int j = c1; j <= c2; j++) {
                        cells.push_back(matrix[i][j]);
                    }
                }
            }
        }
    
        if(matrix[h][w] == NULL) {
            matrix[h][w] = new Cell(cells);
        } else {
            matrix[h][w]->change(cells);
        }
        return matrix[h][w]->get();
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */