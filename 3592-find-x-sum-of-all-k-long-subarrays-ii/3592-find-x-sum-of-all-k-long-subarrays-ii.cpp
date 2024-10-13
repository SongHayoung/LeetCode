struct Node {
    Node *l, *r, *p;
    pair<long long, long long> key;
    long long sum, subset;
    Node(pair<long long, long long> key, Node* p) : key(key), sum(key.first * key.second), subset(1), l(nullptr), r(nullptr), p(p) {}
    void update() {
        subset = 1;
        sum = key.first * key.second;
        if(l) subset += l->subset, sum += l->sum;
        if(r) subset += r->subset, sum += r->sum;
    }
};

struct SplayTree {
    Node* tree;
    SplayTree() : tree(nullptr) {
        insert({INT_MIN, 0});
        insert({INT_MAX, 0});
    }

    void rotate(Node *x) {
        Node *p = x->p, *b;
        if (x == p->l) {
            p->l = b = x->r;
            x->r = p;
        } else {
            p->r = b = x->l;
            x->l = p;
        }
        x->p = p->p;
        p->p = x;
        if (b) b->p = p;
        (x->p ? p == x->p->l ? x->p->l : x->p->r : tree) = x;
        p->update();
        x->update();
    }

    void splay(Node *x, Node *g = nullptr) {
        Node* y;
        while(x->p != g){
            Node* p = x->p;
            if(p->p == g){
                rotate(x); break;
            }
            auto pp = p->p;
            if((p->l == x) == (pp->l == p)){
                rotate(p); rotate(x);
            } else {
                rotate(x); rotate(x);
            }
        }
        if(!g) tree = x;
    }
    void insert(pair<long long, long long> key) {
        if(!tree) {
            tree = new Node(key, nullptr);
            return;
        }
        Node *p = tree, **pp;
        while (1) {
            if (key == p->key) return;
            if (key < p->key) {
                if (!p->l) {
                    pp = &p->l;
                    break;
                }
                p = p->l;
            } else {
                if (!p->r) {
                    pp = &p->r;
                    break;
                }
                p = p->r;
            }
        }
        *pp = new Node(key, p);
        splay(*pp);
    }
    bool find(pair<long long, long long> key) {
        Node *p = tree;
        if (!p) return false;
        while (p) {
            if (key == p->key) break;
            if (key < p->key) {
                if (!p->l) break;
                p = p->l;
            } else {
                if (!p->r) break;
                p = p->r;
            }
        }
        splay(p);
        return key == p->key;
    }

    void remove(pair<long long, long long> key) {
        if (!find(key)) return;
        Node *p = tree;
        if (p->l and p->r) {
            tree = p->l, tree->p = nullptr;
            Node *x = tree;
            while (x->r) x = x->r;
            x->r = p->r, p->r->p = x;
            splay(x), tree->update();
            delete p; return;
        }
        if(p->l) {
            tree = p->l, tree->p = nullptr;
            tree->update();
            delete p; return;
        }
        if (p->r) {
            tree = p->r, tree->p = nullptr;
            tree->update();
            delete p; return;
        }
        delete p;
        tree = nullptr;
    }

    void kth(int k) {
        Node* x = tree;
        while(1){
            while(x->l && x->l->subset > k) x = x->l;
            if(x->l) k -= x->l->subset;
            if(!k--) break;
            x = x->r;
        }
        splay(x);
    }

    Node* gather(int l, int r) {
        l += 1, r += 1;
        kth(r+1);
        Node* x = tree;
        kth(l-1);
        splay(x, tree);
        return tree->r->l;
    }

    long long sum(int l, int r) {
        return gather(l,r)->sum;
    }
};

class Streamer {
    deque<int> streams;
    SplayTree* st;
    unordered_map<long long, long long> freq;
    int limit, x;
public:
    Streamer(int k, int x) : limit(k), x(x), st(new SplayTree()) {}
    
    void update(int x, int operation) {
        if(freq.count(x)) {
            st->remove({freq[x], x});
        }
        freq[x] += operation;
        if(freq[x] == 0) freq.erase(x);
        else st->insert({freq[x], x});
    }
    
    long long query(int n) {
        streams.push_back(n);
        update(streams.back(),1);
        
        if(streams.size() > limit) {
            update(streams.front(), -1);
            streams.pop_front();
        }
        if(streams.size() != limit) return -1;
        if(freq.size() <= x) return st->tree->sum;
        return st->sum(freq.size() - x, freq.size() - 1);
    }
};
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        Streamer* s = new Streamer(k,x);
        vector<long long> res;
        for(int i = 0; i < nums.size(); i++) {
            long long now = s->query(nums[i]);
            if(now != -1) res.push_back(now);
        }
        return res;
    }
};