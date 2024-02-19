#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode*children[26];
    int childCount;
    bool isTreminal;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        childCount=0;
        isTreminal=false;
    }
};
class Trie{
    public:
    TrieNode*root;
    Trie(char ch){
        root=new TrieNode(ch);
    }
    void insertUtil(TrieNode*root,string word){
        if(word.length()==0){
            root->isTreminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode*child;
        if(root->children!=NULL){
            child=root->children[index];
        }else{
            child=new TrieNode(word[0]);
            root->childCount++;
            root->children[index]=child;
        }
        insertUtil(child,word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root,word);
    }
    void lcp(string str,string &ans){
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(root->childCount==1){
                ans.push_back(ch);
                int index=ch-'a';
                root=root->children[index];
            }else{
                break;
            }
            if(root->isTreminal){
                break;
            }
        }
    }
};
// first approach
string longestCommonPrefix(vector<string>&strs){
    string ans="";
    for(int i=0;i<strs[0].length();i++){
        char ch=strs[0][i];
        bool match=true;
        for(int j=1;j<strs.size();j++){
            if(strs[j].size()<i||ch!=strs[j][i]){
                match=false;
                break;
            }
        }
        if(match==false){
            break;
        }else{
            ans.push_back(ch);
        }
        return ans;
    }
}
// second approach

string longestCommonPrefix(vector<string>&strs){
    Trie*t=new Trie('\0');
    for(int i=0;i<strs.size();i++){
        t->insertWord(strs[i]);
    }
    string first=strs[0];
    string ans="";
    t->lcp(first,ans);
    return ans;
}