// lowest common ancestor
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
Node*lowestCommonAncestor(Node*root,Node*p,Node*q){
    if(root==NULL){
        return NULL;
    }
    if(root->data<p->data&&root->data<q->data){
        return lowestCommonAncestor(root->right,p,q);
    }    
    if(root->data>p->data&&root->data>q->data){
        return lowestCommonAncestor(root->left,p,q);
    }
    return root;
}