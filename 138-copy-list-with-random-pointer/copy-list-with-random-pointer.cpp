/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
void insertattail(Node* &head,Node* &tail,int d){
    Node* newnode = new Node(d);
    if(head==nullptr){
        head = newnode;
        tail = newnode;
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
}
public:
    Node* copyRandomList(Node* head) {
        //step1 = clone linked list banao
        Node* clonehead = nullptr;
        Node* clonetail = nullptr;
        Node* temp = head;
        
        while(temp!=nullptr){
            insertattail(clonehead,clonetail,temp->val);
            temp = temp->next;
        }
        //step 2 = map banao
        unordered_map<Node*,Node*> mapping;
        Node* originalnode = head;
        Node* clonenode = clonehead;
        while(originalnode!=nullptr&&clonenode!=nullptr){
            mapping[originalnode]=clonenode;
            originalnode = originalnode->next;
            clonenode = clonenode->next;
        }
        originalnode = head;
        clonenode = clonehead;
        while(originalnode!=nullptr){
            clonenode->random = mapping[originalnode->random];
            originalnode = originalnode->next;
            clonenode = clonenode->next;
        }
        return clonehead;       
    }
};