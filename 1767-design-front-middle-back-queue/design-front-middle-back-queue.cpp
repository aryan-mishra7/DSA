class Node{
    public:
    int val;
    Node* prev;
    Node* next;
    Node(int val){
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
class FrontMiddleBackQueue {
private:
void insertathead(Node* &head,Node*&tail,int val){
    Node* newnode = new Node(val);
    if(head==nullptr){
        head = newnode;
        tail = newnode;
        return;
    }
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}
void insertattail(Node* &head,Node* &tail,int val){
    Node* newnode = new Node(val);
    if(head==nullptr){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
public:
    Node* head=nullptr;
    Node* tail = nullptr;
    int cnt;
    FrontMiddleBackQueue() {
        cnt = 0;
    }
    
    void pushFront(int val) {
        insertathead(head,tail,val);
        cnt++;
    }
    
void pushMiddle(int val) {
    if (head==nullptr) {
        insertathead(head,tail,val);
    }
    else {
        Node* slow = head;
        Node* fast = head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* newnode = new Node(val);
        if(slow==head){
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        else{
            Node* temp = slow->prev;
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = slow;
            slow->prev = newnode;
        }
    }

    cnt++;
}
    
void pushBack(int val) {
    insertattail(head,tail,val);
    cnt++;
}
int popFront() {
    if(head==nullptr)
        return -1;
    Node* temp = head;
    int val = temp->val;
    head = head->next;
    if(head!=nullptr)
    head->prev = nullptr;
    else
    tail = nullptr;
    delete temp;
    cnt--;
    return val;
}
    
int popMiddle() {
    if(head == nullptr)
        return -1;
    Node* slow = head;
    Node* fast = head;
    while (fast->next!=nullptr&&fast->next->next!=nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    int val = slow->val;
    if(slow->prev!=nullptr)
    slow->prev->next=slow->next;
    else
    head=slow->next;
    if(slow->next!=nullptr)
    slow->next->prev = slow->prev;
    else
    tail = slow->prev;
    delete slow;
    cnt--;
    return val;
}
    
    int popBack() {
    if(tail==nullptr)
     return -1;
    Node* temp = tail;
    int val = temp->val;
    tail = tail->prev;
    if(tail!=nullptr)
    tail->next = nullptr;
    else
    head = nullptr;
    delete temp;
    cnt--;
    return val;
    }
};
/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */