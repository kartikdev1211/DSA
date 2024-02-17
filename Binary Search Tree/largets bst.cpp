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
class info{
    public:
    int maxi,mini;
    bool bst;
    int size;
};
info solve(Node*root,int &ans){
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }
    info left=solve(root->left,ans);
    info right=solve(root->right,ans);
    info currNode;
    currNode.size=left.size+right.size;
    currNode.maxi=max(root->data,right.maxi);
    currNode.mini=min(root->data,left.mini);
    if(left.bst&&right.bst&&(root->data>left.maxi&&root->data<right.mini)){
        currNode.bst=true;
    }else{
        currNode.bst=false;
    }
    if(currNode.bst){
        ans=max(ans,currNode.size);
    }
    return currNode;
}
int largetsBST(Node*root){
    int maxSize=0;
    info temp=solve(root,maxSize);
    return maxSize;
}