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
pair<int,int>predecessorSuccessor(Node*root,int key){
    Node*temp=root;
    int pred=-1,succ=-1;
    while(temp->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
        }else{
            pred=temp->data;
            temp=temp->right;
        }
    }
    Node*leftTree=temp->left;
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }
    Node*rightTree=temp->right;
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }
    pair<int,int> ans=make_pair(pred,succ);
    return ans;
}