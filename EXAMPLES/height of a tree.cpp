#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data){
    struct Node *temp;
    temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


// recursive function to calculate height   
int height(struct Node *node){
    if(node == NULL){
        return 0;
    }

    int leftDepth = height(node->left);
    int rightDepth = height(node->right);

    if(leftDepth > rightDepth){
        return leftDepth + 1;
    }else{
        return rightDepth + 1;
    }

}

int main(){ 
    struct Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->right->left = newNode(4); 
    root->left->right = newNode(5); 

    cout<<height(root);
}