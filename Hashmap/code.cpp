#include<bits/stdc++.h>
using namespace std;
int main(){
    // creation
    unordered_map<string,int>m;
    // insertion
    pair<string,int>p=make_pair("kartik",3);
    m.insert(p);
    pair<string,int>pair2=make_pair("kashyap",2);
    m.insert(pair2);
    m["mera"]=1;
    //searhing
    cout<<m["mera"]<<endl;
    cout<<m.at("kashyap")<<endl;
    // cout<<m.at("unknownKey")<<endl;
    cout<<m["unknownKey"]<<endl;
    cout<<m.at("unknownKey")<<endl;
    // size
    cout<<m.size()<<endl;
    //check presence
    cout<<m.count("kartik")<<endl;
    //erase
    m.erase("kartik");
    cout<<m.size()<<endl;
    //iterator
    unordered_map<string,int>:: iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    return 0;
}