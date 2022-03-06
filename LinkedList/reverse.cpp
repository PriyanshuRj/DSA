#include<bits/stdc++.h>
using namespace std;
class Node{
    private:
        int data;
        Node *next;
    public:
        void initialize();
        void insert();
        Node * reverse();
        void display();

    
};
void Node::initialize(){
    cout<<"Enter the first element of the linked list :";
    cin>>this->data;
    this->next = NULL;
}
void Node :: insert(){
    Node *n = new Node;
    Node *p = this;
    cout<<"Enter the data for this element : ";
    cin>>n->data;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = n;
    n->next =  NULL;
}
Node *Node:: reverse(){
    Node *p = this;
    Node *q = NULL;
    Node *r = NULL;
    while(p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}
void Node:: display(){
    Node *n = this;
    while(n!=NULL){
        cout<<"The data at this node is : "<<n->data<<endl;
        n = n->next;
    }
}

int main(){
    Node *head = new Node;
    head->initialize();
    head->insert();
    head->insert();
    head->insert();
    head->insert();
    head->display();
    

    head = head->reverse();
    head->display();
    return 0;
}