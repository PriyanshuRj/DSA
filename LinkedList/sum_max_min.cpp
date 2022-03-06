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
void append(struct Node *head,int value){
    while(head->next !=NULL) head = head->next;
    struct Node* next = (struct Node*)malloc(sizeof(struct Node));
    next->data = value;
    next->next = NULL;
    head->next = next;
}
struct Node *first_insert(struct Node *head,int value){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = head;
    return new_node;
}
void insert(struct Node *head,int data,int index){
    
    int counter = 1;
    while(head != NULL && counter <index-1){
        counter++;
        head = head->next;
    }
    if(counter != index-1){
        cout<<endl<<"Index out of boud"<<endl<<endl;
        return;
    }
    struct Node *next = (struct Node*)malloc(sizeof(struct Node));
    next->data = data;
    next->next = head->next;
    head->next =  next;
}
void sum(struct Node *head){
    long long sumnum = 0;
    while(head != NULL){
        sumnum += head->data;
        head = head->next;
    }
    cout<<"The sum of all number in the list is : "<<sumnum<<endl<<endl;
}
void max(struct Node *head){
    long long maxnum = -99999;
    while(head != NULL){
        if(head->data >maxnum)
            maxnum = head->data;
        head = head->next;
    }
    cout<<"The maxnimum number in the list is : "<<maxnum<<endl<<endl;
}
void min(struct Node *head){
    long long minnum = 9999999;
    while(head != NULL){
        if(head->data < minnum)
            minnum = head->data;
        head = head->next;
    }
    cout<<"The minnimum number in the list is : "<<minnum<<endl<<endl;
}
int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    cout<<"Enter the data for the first node : ";
    int data;
    cin>>data;
    initialize(head,data);
    while(true){
        int ans;
        cout<<"\nPress 1 for adding node\nPress 2 for displaying nodes\nPress 3 for inserting at a specific index\n4Press 4 for max number in the linked list\nPress 5 for min number in the list\nPress 7 for sum of all elements\n0 for exiting\n\nchoice : ";
        cin>>ans;
        if(ans==0) break;
        else if(ans==1){
            cout<<"Enter the data for the next node : ";
            int data;
            cin>>data;
            append(head,data);
        }
        else if(ans==2){
            display(head);
        }
        else if(ans==3){
            int ind;
            cout<<"Enter the index : ";
            cin>>ind;
            cout<<"Enter the data for the next node : ";
            int data;
            cin>>data;
            if(ind==1) head = first_insert(head,data);
            else insert(head,data,ind);

        }
        else if(ans==4) max(head);
        else if(ans==5) min(head);
        else if(ans==7) sum(head);
        else {
            cout<<"Wrong choice please try aggain !!!"<<endl;
        }
        
    }
}