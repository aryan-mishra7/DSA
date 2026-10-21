class Node {
public:
    string s;
    Node* next;
    Node* prev;
    Node(string s){
        this->s = s;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class BrowserHistory {
private:
    void insertattail(Node* &head,Node* &tail,string s){
        Node* newnode = new Node(s);
        if(head == nullptr){
            head = newnode;
            tail = newnode;
        } 
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* curr = nullptr;

    BrowserHistory(string homepage) {
        insertattail(head,tail,homepage);
        curr = head;
    }

    void visit(string url) {
        curr->next = nullptr;
        tail = curr;
        insertattail(head,tail,url);
        curr = tail;
    }
    string back(int steps) {
        while(steps>0&&curr->prev!=nullptr){
            curr = curr->prev;
            steps--;
        }
        return curr->s;
    }
    string forward(int steps) {
        while(steps>0&&curr->next!=nullptr){
            curr = curr->next;
            steps--;
        }
        return curr->s;
    }
};
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
