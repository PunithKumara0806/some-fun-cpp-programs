#include<iostream>
#include<fstream>
using namespace std;
typedef struct n{
    int value;
    struct n *next;
}node;
void display(node *a){
    while(a != NULL){
        cout<<a->value<<" ";
        a = a->next;
    }
    cout<<endl;
}
node* ReverseLinkedList(node *a){       //  a1  b1  c1   ==>          a1  b1   c1
    node *a1,*b1,*c1;                   //  a-> b-> c->       null <- a   b-> c->
                                        //
    a1 = a;
    b1  = a->next;
    a->next = NULL;
    while(1)
    {
        c1 = b1->next;
        b1->next = a1;
        a1 = b1;
        b1 = c1;
        if(c1 == NULL){
            break;
        }
        
    }
    return a1;
}
int main(){
    ifstream file;
    file.open("input_file/linkedlist.txt");
    if(file){
        int n;
        file>>n;
        node *head,*traverse;
        head = (node*)malloc(sizeof(node));
        file>>head->value;
        traverse = head;
        for(int i = 1; i < n; i++){
            traverse->next = (node*)malloc(sizeof(node));
            traverse = traverse->next;
            file>>traverse->value;
        }
        traverse->next = NULL;
        display(head);
        head = ReverseLinkedList(head);
        display(head);
    }
    return 0;
}