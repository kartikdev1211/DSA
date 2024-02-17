#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i,right=2*i+1;
    if(left<=n&&arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n&&arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
    int t=n;
    while(t>1){
        swap(arr[t],arr[1]);
        t--;
        heapify(arr,t,1);
    }
}
int main(){
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"Printing the array: "<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    heapSort(arr,n);
    cout<<"Printing the array: "<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    cout<<"Using priority queue here"<<endl;
    // max heap
    priority_queue<int>pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout<<"Element at top: "<<pq.top()<<endl;
    // min heap
    priority_queue<int,vector<int>,greater<int>>minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);
    cout<<"Element at top: "<<minHeap.top()<<endl;
}