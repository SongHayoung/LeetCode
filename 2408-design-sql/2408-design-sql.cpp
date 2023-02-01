class SQL {
    unordered_map<string, int> ids;
    unordered_map<string, vector<vector<string>>> table;
    int incr(string name) {
        int id = ids[name];
        ids[name] += 1;
        return id;
    }
public:
    SQL(vector<string>& names, vector<int>& columns) {
        for(int i = 0; i < names.size(); i++) {
            string name = names[i];
            ids[name] = 1;
            table[name].push_back(vector<string>(columns[i]));
        }
    }

    void insertRow(string name, vector<string> row) {
        if(!ids.count(name)) return;
        int id = incr(name);
        table[name].push_back(row);
    }

    void deleteRow(string name, int rowId) {
        if(!table.count(name)) return;
        if(table[name].size() <= rowId) return;
        table[name][rowId] = {};
    }

    string selectCell(string name, int rowId, int columnId) {
        if(!table.count(name)) return "";
        if(table[name].size() <= rowId) return "";
        if(table[name][rowId].size() < columnId) return "";
        return table[name][rowId][columnId-1];
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * obj->insertRow(name,row);
 * obj->deleteRow(name,rowId);
 * string param_3 = obj->selectCell(name,rowId,columnId);
 */