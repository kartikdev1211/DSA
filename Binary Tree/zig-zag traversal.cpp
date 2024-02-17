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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<Node*>q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty()){
            int size=q.size();
            vector<int>currAns(size);
            for(int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();
                int index=(leftToRight)?i:(size-1-i);
                currAns[index]=front->data;
                if(front->left!=NULL){
                  q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
            ans.push_back(currAns);
            leftToRight=!leftToRight;
        }
        return ans;
    }
};