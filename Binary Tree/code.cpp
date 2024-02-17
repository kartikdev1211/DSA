#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
Node*buildTree(Node*root){
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data inserting left: "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting right: "<<data<<endl;
    root->right=buildTree(root->right);
}
void levelOrderTraversal(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void inorder(Node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node*root){
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node*root=NULL;
    // creation of tree
    root=buildTree(root);
    // level order traversal
    levelOrderTraversal(root);
    cout<<"Inorder traversal is: ";
    inorder(root);
    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 