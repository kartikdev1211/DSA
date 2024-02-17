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
bool twoSumInBST(Node*root,int target){
    vector<int>inorderValue;
    inorder(root,inorderValue);
    int i=0,j=inorderValue.size()-1;
    while(i<j){
        int sum=inorderValue[i]+inorderValue[j];
        if(sum==target){
            return true;
        }else if(sum>target){
            j--;
        }else{
            i++;
        }
    }
    return false;
}