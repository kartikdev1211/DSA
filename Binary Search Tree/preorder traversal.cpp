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
Node*solve(vector<int>&preorder,int mini,int maxi,int &index){
    if(index>=preorder.size()){
        return NULL;
    }
    if(preorder[index]<mini||preorder[index]>maxi){
        return NULL;
    }
    Node*root= new Node(preorder[index++]);
    root->left=solve(preorder,mini,root->data,index);
    root->right=solve(preorder,root->data,maxi,index);
    return root;
}
Node*bstFromPreorder(vector<int>&preorder){
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int i=0;
    return solve(preorder,mini,maxi,i);
}   