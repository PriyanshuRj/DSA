#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
};

void insertion(struct Node *& head){
    struct Node *p = head;
    while(p->next != NULL) p = p->next;
    struct Node *nxt = new struct Node;
    cout<<"Enter the data for the Node : ";
    int data;
    cin>>data;
    nxt->data = data;
    nxt->next = NULL;
    p->next = nxt;
}
struct Node *initialize(){
    struct Node *head = new Node;
    cout<<"Enter the data of the first node : ";
    cin>>head->data;
    head->next = NULL;
    return head;
}

void display(struct Node *head){
    while(head != NULL){
        cout<<"The data at the node is : "<<head->data<<endl;
        head = head->next;
    }
}
int main(){
    cout<<"Initializing the stack";
    struct Node* head = initialize();
    while(true){
        cout<<"Enter your choice : ";
        int cond;
        cin>>cond;
        if(cond == 0) break;
        else if(cond == 1) insertion(head);
        else if (cond == 2) display(head);
    }
    display(head);
    return 0;
}