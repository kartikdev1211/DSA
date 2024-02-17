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
void inorder(Node*root,vector<int>&in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
Node*inorderToBST(int s,int e,vector<int>in){
    if(s>e){
        return NULL;
    }
    int mid=s+(e-s)/2;
    Node*root=new Node(in[mid]);
    root->left=inorderToBST(s,mid-1,in);
    root->right=inorderToBST(mid+1,e,in);
    return root;
}
Node*balanceBST(Node*root){
    vector<int>inorderVal;
    inorder(root,inorderVal);
    return inorderToBST(0,inorderVal.size()-1,inorderVal);
}