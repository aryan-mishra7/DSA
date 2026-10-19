class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        this->val = data;
        this->next = nullptr;
    }
};
class MyLinkedList {
private:
void insertathead(Node* &head,Node* &tail,int value){
    Node* newnode = new Node(value);
    if(head==nullptr){
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}
void insertattail(Node* &head,Node*&tail,int value){
    Node *newnode = new Node(value);
    if(head==nullptr){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
public:
        Node* head=nullptr;
        Node* tail=nullptr;
        int k;
    MyLinkedList() {
        k=0;
    }
    
    int get(int index) {
        if(index<0||index>=k)
        return -1;
        int cnt=0;
        Node* temp=head;
        while(cnt<index){
            temp = temp->next;
            cnt++;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        insertathead(head,tail,val);
        k++;
    }
    
    void addAtTail(int val) {
        insertattail(head,tail,val);
        k++;
    }
    
void addAtIndex(int index, int val) {
    if(index<0||index>k)
        return;
    if(index == 0){
        insertathead(head, tail, val);
        k++;
        return;
    }
    if(index==k){
        insertattail(head, tail, val);
        k++;
        return;
    }
    Node* prev = head;
    int cnt = 0;
    while(cnt<index-1){
        prev = prev->next;
        cnt++;
    }
    Node* newnode = new Node(val);
    newnode->next = prev->next;
    prev->next = newnode;
    k++;
}
    
    void deleteAtIndex(int index) {
        if(index<0||index>=k)
            return;
        if(index==0){
            Node* temp = head;
            head = head->next;
            delete temp;
            k--;
            if(k==0)
                tail = nullptr;
            return;
        }
        Node* prev = head;
        int cnt = 0;
        while(cnt<index-1){
            prev = prev->next;
            cnt++;
        }
        Node* curr = prev->next;
        prev->next = curr->next;
        if(curr==tail)
            tail = prev;
        delete curr;
        k--;
    }
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