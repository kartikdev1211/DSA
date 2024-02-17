#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int d){
        this->data=d;
        this->left,this->right=NULL;
    }
};
class Solution {
    private:
    void createMapping(vector<int>inorder,map<int,int>&nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]]=i;
        }
    }
    Node*solve(vector<int>inorder,vector<int>postorder,int index,int inOrderStart,int inOrderEnd,int n,map<int,int>&nodeToIndex){
        if(index<0||inOrderStart>inOrderEnd){
            return NULL;
        }
        int element=postorder[index--];
        Node*root=new Node(element);
        int position=nodeToIndex[element];
        root->right=solve(inorder,postorder,index,position+1,inOrderEnd,n,nodeToIndex);
        root->left=solve(inorder,postorder,index,inOrderStart,position-1,n,nodeToIndex);
        return root;
    }
    public:
    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int postOrderIndex=n-1;
        map<int,int>nodeToIndex;
        createMapping(inorder,nodeToIndex,n);
        Node*ans=solve(inorder,postorder,postOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
    }
};