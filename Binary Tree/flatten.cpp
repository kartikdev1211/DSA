#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node*right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
class Solution{
    public:
    void flatten(Node*root){
        Node*curr=root;
        while(curr!=NULL){
            if(curr->left){
                Node*predecessor=curr->left;
                while(predecessor->right){
                    predecessor=predecessor->right;
                }
                predecessor->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
        
    }
};