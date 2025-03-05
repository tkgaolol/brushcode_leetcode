class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int val) : val(val), next(nullptr) {}
    };

    MyLinkedList() {
        _dummyHead = new Node(0);
        _size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= _size) return -1;
        Node *head = _dummyHead->next;
        int i = 0;
        while (i!=index)
        {
            head = head->next;
            i++;
        }
        return head->val;
    }
    
    void addAtHead(int val) {
        Node *new_head = new Node(val);
        new_head->next = _dummyHead->next;
        _dummyHead->next = new_head;
        _size++;
    }
    
    void addAtTail(int val) {
        Node *new_tail = new Node(val);
        Node *currtail = _dummyHead;
        while(currtail->next != nullptr)
        {
            currtail = currtail->next;
        }
        currtail->next = new_tail;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > _size) return;
        if(index == _size)
        {
            addAtTail(val);
            return;
        }
        Node *add = _dummyHead;
        int i = 0;
        while (i<index)
        {
            add = add->next;
            i++;
        }
        Node* temp = new Node(val);
        temp->next = add->next;
        add->next = temp;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= _size) return;
        Node *remove = _dummyHead;
        int i = 0;
        while (i<index)
        {
            remove = remove->next;
            i++;
        }
        Node* temp = remove->next;
        remove->next = temp->next;
        delete temp;
        _size--;
    }

private:
    int _size;
    Node* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */ 