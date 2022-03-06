#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void initialize(struct Node* head,int data){
    head->data = data;
    head->next = NULL;
}
void countNodes(struct Node* head){
    int counter =1;
    while(head->next !=NULL){
        counter++;
        head = head->next;
    }
    cout<<endl<<"The linked list curently contains "<<counter<<" Nodes"<<endl;
}
void append(struct Node *head,int value){
    while(head->next !=NULL) head = head->next;
    struct Node* next = (struct Node*)malloc(sizeof(struct Node));
    next->data = value;
    next->next = NULL;
    head->next = next;
}
int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    cout<<"Enter the data for the first node : ";
    int data;
    cin>>data;
    initialize(head,data);
    while(true){
        int ans;
        cout<<"\nPress 1 for adding node\nPress 2 for displaying number of nodes\n0 for exiting\n\nchoice : ";
        cin>>ans;
        if(ans==0) break;
        else if(ans==1){
            cout<<"Enter the data for the next node : ";
            int data;
            cin>>data;
            append(head,data);
        }
        else if(ans==2){
            countNodes(head);
        }
        else {
            cout<<"Wrong choice please try aggain !!!"<<endl;
        }
    }
}