struct FileTree{
    unordered_map<string, FileTree*> directory;
    unordered_map<string, string> files;
    
    FileTree(){};
    FileTree* insertDir(string& p) {
        if(!directory.count(p)) directory[p] = new FileTree();
        return directory[p];
    }
    FileTree* getDir(string& p) {
        return directory[p];
    }
    void insertFile(string& f, string& c) {
        files[f] += c;
    }
    bool isDir(string& p) {
        return directory.count(p);
    }
    bool isFile(string& p) {
        return files.count(p);
    }
    bool hasFile() {
        return !files.empty();
    }
};
class FileSystem {
    FileTree* ft;
    string parse(string& s, int& i) {
        string res = "";
        while(i < s.length() and s[i] != '/') {
            res += s[i++];
        }
        i++;
        return res;
    }
    vector<string> _ls(FileTree* f) {
        vector<string> res;
                    
        for(auto [k, _] : f->directory)
            res.push_back(k);
                    
        for(auto [k, _] : f->files)
            res.push_back(k);
                    
        sort(begin(res),end(res));
        
        return res;
    }
public:
    FileSystem() {
        ft = new FileTree();
    }
    
    vector<string> ls(string path) {
        int i = 1;
        FileTree* f = ft;
        while(i < path.length()) {
            auto p = parse(path,i);
            if(i >= path.length()) {
                if(f->isFile(p))
                    return {p};
                else {
                    f = f->getDir(p);
                           
                    return _ls(f);
                }
            } else {
                f = f->getDir(p);
            }
        }
        return _ls(f);
    }
    
    void mkdir(string path) {
        int i = 1;
        FileTree* f = ft;
        while(i < path.length()) {
            auto p = parse(path,i);
            f = f->insertDir(p);
        }
    }
    
    void addContentToFile(string filePath, string content) {
        int i = 1;
        FileTree* f = ft;
        while(i < filePath.length()) {
            auto p = parse(filePath,i);
            if(i >= filePath.length()) {
                f->insertFile(p,content);
            } else {
                f = f->insertDir(p);
            }
        }
    }
    
    string readContentFromFile(string filePath) {
        int i = 1;
        FileTree* f = ft;
        while(i < filePath.length()) {
            auto p = parse(filePath,i);
            if(i >= filePath.length()) {
                return f->files[p];
            } else {
                f = f->insertDir(p);
            }
        }
        return "";
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */