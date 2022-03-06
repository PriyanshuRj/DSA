#include<bits/stdc++.h>
using namespace std;
class Node{
    private:
        int data;
        Node *next;
    public:
        void initialize();
        void insert();
        bool issorted();
        void display();
        void remove_duplicate();
    
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
bool Node :: issorted(){
    Node *p = this;
    while(p->next != NULL){
        if(p->data > p->next->data) break;
        p = p->next;
    }
    if(p->next==NULL) return true;
    else return false;
    
} 
void Node :: remove_duplicate(){
    Node *p = this;
    while(p->next !=NULL){
        if(p->data == p->next->data){
            Node *q = p->next;
            p->next = p->next->next;
            delete q;
        }
        else p = p->next;
    }

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
    if(head->issorted() == true){
        head->remove_duplicate();
        
    }

    else cout<<"Unsorted linked list "<<endl;
    head->display();
    return 0;
}