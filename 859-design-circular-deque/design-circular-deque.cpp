class node{
public:
int data;
node* next;

node(int data){
    this->data = data;
    this->next = nullptr;
}
};
class MyCircularDeque {
private:
void insertathead(node* &head,node* &tail,int value){
    node* newnode = new node(value);
    if(head==nullptr){
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}
void insertattail(node* &head,node*&tail,int value){
    node *newnode = new node(value);
    if(head==nullptr){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
node* traverse(node* head,node* tail){
    if(head==nullptr||head->next==nullptr)
        return head;
    node* temp = head;
    while(temp->next!=tail)
        temp = temp->next;
        return temp;
}
public:
    int cnt;
    int size;
    node *head = nullptr;
    node *tail = nullptr;
    MyCircularDeque(int k) {
        cnt = 0;
        size = k;
    }
    
    bool insertFront(int value) {
        if(cnt==size)
        return false;
        insertathead(head,tail,value);
        cnt++;
        return true;
    }
    
    bool insertLast(int value) {
        if(cnt==size)
        return false;
        insertattail(head,tail,value);
        cnt++;
        return true;
    }
    
    bool deleteFront() {
        if(head==nullptr)
            return false;
        node* temp = head;
        head = head->next;
        if(head==nullptr)
            tail = nullptr;
        delete temp;
        cnt--;
        return true;
    }
    
    bool deleteLast() {
        if(head==nullptr)
            return false;
        if(head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else{
            node* temp=traverse(head, tail);
            delete tail;
            tail = temp;
            tail->next = nullptr;
    }
    cnt--;
    return true;
}
    
    int getFront() {
        if(head==nullptr)
        return -1;
        return head->data;
    }
    
    int getRear() {
        if(head==nullptr)
        return -1;
        return tail->data;
    }
    
    bool isEmpty() {
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */