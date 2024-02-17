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
bool isBST(Node*root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data>=min&&root->data<=max){
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        return left&&right;
    }else{
        return false;
    }
}
bool isValidBST(Node*root){
    return isBST(root,INT_MIN,INT_MAX);
}