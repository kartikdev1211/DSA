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
Node*minVal(Node*root){
    Node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node*maxVal(Node*root){
    Node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
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
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
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
Node* insertIntoBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data>root->data){
        // right part insertion
        root->right=insertIntoBST(root->right,data);
    }else{
        root->left=insertIntoBST(root->left,data);
    }
    return root;
}
void takeInput(Node*&root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
}
int main(){
    Node*root=NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);   
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root); 
    cout<<endl<<"Printing inorder"<<endl;
    inorder(root);
    // cout<<endl<<"Printing preorder"<<endl;
    // preorder(root);
    // cout<<endl<<"Printing postorder"<<endl;
    // postorder(root);
    cout<<"Minimum value is: "<<minVal(root)<<endl;
    cout<<"Maximum value is: "<<maxVal(root)<<endl;
    return 0;
}