#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* node(int value){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void leverorder(struct Node *root){
    queue<struct Node *> q;
    q.push(root);

    while(!q.empty()){
        struct Node *node = q.front();
        q.pop();
        if(node->left != NULL){
            q.push(node->left);
        }

        if(node->right != NULL){
            q.push(node->right);
        }
        
        cout<<node->data<<" ";

    }

}

int main(){
    struct Node *root,*temp;

    root = node(1);

    temp = node(2);
    root->left = temp;

    temp = node(6);
    root->right = temp;


    temp = node(9);
    root->left->right = temp;

    temp = node(8);
    root->left->left = temp;

    leverorder(root);

}