#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void createList(struct Node *head,int size){

    struct Node *last;
    last = head;

    for(int i = 1;i<size;i++){
        struct Node *temp = new Node();
        cout<<"Enter value:";
        cin>>temp->data;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    last->next = head;
}

void printList(struct Node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next; 
    }
}

// flodys hare and tortoise
bool detectLoop(struct Node* &head){
        struct Node *hare,*tortoise;

        hare = head;
        tortoise = head;

        while(hare && tortoise && tortoise->next){
            hare = hare->next;
            tortoise = tortoise->next->next;

            if(hare == tortoise){
                return 1;
            }

        }

        return 0;
}
    

int main(){

    struct Node *head;
    head = new Node();
    cout<<"Enter value:";
    cin>>head->data;
    head->next = NULL;

    createList(head,5);
    printList(head);
    cout<<"\n";

    cout<<detectLoop(head);

}