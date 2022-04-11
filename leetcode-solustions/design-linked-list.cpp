class MyLinkedList {
    struct Node {
        int val;
        Node* next;
    };
private:
    Node* head;
    Node* tail;

private:
    Node* getNode(int index) {
        Node* cur = head;
        for(int i = 0; i < index - 1; i++) {
            cur = cur->next;
            if(cur == tail)
                return cur;
        }

        return cur;
    }
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->head = new Node{-1, nullptr};
        tail = head;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node* cur = getNode(index);

        return index == 0 ? head->val : cur == tail || cur->next == tail ? -1 : cur->next->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        this->head = new Node{val, this->head};
        return ;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* newTail = new Node{-1, nullptr};
        this->tail->val = val;
        this->tail->next = newTail;
        this->tail = newTail;
        return ;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == 0) {
            addAtHead(val);
        } else {
            Node *cur = getNode(index);

            if (cur != tail) {
                Node *newNode = new Node{val, cur->next};
                cur->next = newNode;
            }
        }

        return ;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node* cur = getNode(index);

        if(index == 0) {
            head = head->next;
        } else if(cur != tail && cur->next != tail) {
            cur->next = cur->next->next;
        }

        return ;
    }
};
