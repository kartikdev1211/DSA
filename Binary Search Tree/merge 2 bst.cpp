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
// Approach 1
void inorder(Node*root,vector<int>&in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
vector<int>mergeArrays(vector<int>&a,vector<int>&b){
    vector<int>ans(a.size()+b.size());
    int i=0,j=0;
    int k=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]<b[j]){
            ans[k++]=a[i++];
        }else{
            ans[k++]=b[j++];
        }
    }
    while(i<a.size()){
        ans[k++]=a[i++];
    }
    while(j<b.size()){
        ans[k++]=b[j++];
    }
    return ans;
}
Node*inorderToBST(int s,int e,vector<int>&in){
    if(s>e){
        return NULL;
    }
    int mid=s+(e-s)/2;
    Node*root=new Node(in[mid]);
    root->left=inorderToBST(0,mid-1,in);
    root->right=inorderToBST(mid+1,e,in);
    return root;
}
// Approach 2
void convertIntoSortedDLL(Node*root,Node*&head){
    if(root==NULL){
        return;
    }
    convertIntoSortedDLL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    convertIntoSortedDLL(root->left,head);
}
Node*mergeLL(Node*head1,Node*head2){
    Node*head=NULL;
    Node*tail=NULL;
    while(head1!=NULL&&head2!=NULL){
        if(head1->data<head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head->right;
            }else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head1=head2->right;
            }else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }
    while(head1!=NULL){
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }
    while(head2!=NULL){
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }
    return head;
}
int countNodes(Node*head){
    int n=0,cnt=0;
    Node*temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}
Node*sortedLLToBST(Node*&head,int n){
    if(n<=0||head==NULL){
        return NULL;
    }
    Node*left=sortedLLToBST(head,n/2);
    Node*root=head;
    root->left=left;
    head=head->right;
    root->right=sortedLLToBST(head,n-n/2-1);
    return root;
}
Node*mergeBST(Node*root1,Node*root2){
    // Approach 1
    vector<int>bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);
    vector<int>ans=mergeArrays(bst1,bst2);
    int s=0,e=ans.size()-1;
    return inorderToBST(s,e,ans);
    // Approach 2
    Node*head1=NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left=NULL;
    Node*head2=NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left=NULL;
    Node*head=mergeLL(head1,head2);
    return sortedLLToBST(head,countNodes(head));
}