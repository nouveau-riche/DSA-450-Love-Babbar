#include<iostream>
#include<queue>
#include<stack>

using namespace std;


// structure of the node
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};


// function to create the new Node
struct Node * newNode(int data){
    struct Node *temp;

    temp = new Node();

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


// change according to simple bfs: at place of printing the node push the node in stack 
void reverse_bfs(struct Node *node){
    queue<struct Node *> q;
    stack<int> s;
    q.push(node);

    while(!q.empty()){
        struct Node *front = q.front();
        q.pop();
        s.push(front->data);



        if(front->right != NULL){
            q.push(front->right);
        }

        if(front->left != NULL){
            q.push(front->left);
        }
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}

int main(){

    struct Node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left  = newNode(6); 
    root->right->right = newNode(7);    

    reverse_bfs(root);

}