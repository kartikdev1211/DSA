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
class Solution{
    public:
    bool isSameTree(Node*p,Node*q){
        if(p==NULL&&q==NULL){
            return true;
        }
        if(p==NULL&&q!=NULL){
            return false;
        }
        if(p!=NULL&&q==NULL){
            return false;
        }
        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        bool value=p->data==q->data;
        if(left&&right&&value){
            return true;
        }else{
            return false;
        }
    }
};