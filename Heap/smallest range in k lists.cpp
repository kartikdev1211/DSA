#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    int row,col;
    node(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
};
class compare{
    bool operator()(node*a,node*b){
        return a->data>b->data;
    }
};
class Solution{
    public:
    vector<int>smallestRage(vector<vector<int>>&nums){
        int mini=INT_MAX,maxi=INT_MIN;
        priority_queue<node*,vector<node*>,compare>minHeap;
        int k=nums.size();
        for(int i=0;i<k;i++){
            int element=nums[i][0];
            mini=min(mini,element);
            maxi=max(maxi,element);
            minHeap.push(new node(element,i,0));
        }
        int start=mini;
        int end=maxi;
        while(!minHeap.empty()){
            node*temp=minHeap.top();
            minHeap.pop();
            mini=temp->data;
            if(maxi-mini<end-start){
                start=mini,end=maxi;
            }
            if(temp->col+1<nums.size()){
                maxi=max(maxi,nums[temp->row][temp->col+1]);
                minHeap.push(new node(nums[temp->row][temp->col+1],temp->row,temp->col+1));
            }else{
                break;
            }
        }
        return {end-start+1};
    }
};