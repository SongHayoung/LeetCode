struct SkipNode {
    SkipNode* next;
    SkipNode* down;
    int val;
    SkipNode(int v) : val(v), next(nullptr), down(nullptr) {}
    SkipNode(int v, SkipNode* next, SkipNode* down) : val(v), next(next), down(down) {}
};

class Skiplist {
    SkipNode* head;
public:
    Skiplist() : head(new SkipNode(-1)) {}

    bool search(int target) {
        SkipNode* runner = head;
        while(runner) {
            while(runner->next and runner->next->val < target) runner = runner->next;
            if(runner->next and runner->next->val == target) return true;
            runner = runner->down;
        }
        return false;
    }

    void add(int num) {
        vector<SkipNode*> nodes;
        SkipNode* runner = head;
        while(runner) {
            while(runner->next and runner->next->val < num) runner = runner->next;
            nodes.push_back(runner);
            runner = runner->down;
        }
        
        SkipNode* down = nullptr;
        
        while(!nodes.empty()) {
            auto node = nodes.back(); nodes.pop_back();
            SkipNode* now = new SkipNode(num, node->next, down);
            node->next = now;
            down = now;
            
            if(rand() & 1) break;
        }
    }

    bool erase(int num) {
        if(!search(num)) return false;
        SkipNode* runner = head;
        while(runner) {
            while(runner->next and runner->next->val < num) runner = runner->next;
            if(runner->next and runner->next->val == num) runner->next = runner->next->next;
            runner = runner->down;
        }
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */