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
void display(struct Node *Head){
    int counter = 1;
    while(Head != NULL){
        cout<<"Data at node "<<counter++<<" is : "<<Head->data<<endl;
        Head = Head->next;
    }
}
void recursive_display(struct Node *Head,int counter = 1){
    if(Head == NULL) return;
    cout<<"Data at Node "<<counter<<" is : "<<Head->data<<endl;
    recursive_display(Head->next,++counter);

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
        cout<<"\nPress 1 for adding node\nPress 2 for displaying nodes\n0 for exiting\n\nchoice : ";
        cin>>ans;
        if(ans==0) break;
        else if(ans==1){
            cout<<"Enter the data for the next node : ";
            int data;
            cin>>data;
            append(head,data);
        }
        else if(ans==2){
            recursive_display(head);
        }
        else {
            cout<<"Wrong choice please try aggain !!!"<<endl;
        }
    }
}