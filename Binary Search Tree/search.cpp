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
bool searchInBST(Node*root,int x){
    Node*temp=root;
    while(temp!=NULL){
        if(temp->data==x){
            return 1;
        }
        if(temp->data>x){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    return false;
}