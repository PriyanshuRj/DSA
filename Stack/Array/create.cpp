#include<bits/stdc++.h>
using namespace std;
struct Stack{
    int size;
    int head;
    int *S;
};
void display(struct Stack s){
    for(int i =0;i<s.head;i++){
        cout<<"Thre element at the place(index) "<<i<<" is : "<<s.S[i]<<endl;
    }
}
void insertion(struct Stack *s){
    int element;
    cout<<"Enter the element :";
    cin>>element;
    s->S[s->head] = element;
    s->head++;
}
void deletion(struct Stack *s){
    s->S[s->head] = 0;
    s->head--;
}
int main(){
    struct Stack stack;
    cout<<"Enter the size of Stack : ";
    cin>>stack.size;
    stack.head = -1;
    stack.S = (int *)malloc(stack.size*sizeof(int));
    int ch;
    while(true){
        cout<<"1 for insert\n2 for delection\n3 for displaying\n\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1:
                if(stack.head<stack.size-1){
                    insertion(&stack);
                }
                else cout<<"The stack is full"<<endl;
                break;
            case 2:
                if(stack.head>-1){
                    deletion(&stack);
                }
                else cout<<"The stack is empty"<<endl;
                break;
            case 3:
                display(stack);
                break;
            default:
                break;
        }
    }
    
    return 0;
}