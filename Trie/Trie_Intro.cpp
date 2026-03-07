#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode*children[26];
        bool isTerminal;

        TrieNode(char ch){
            data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};

class Trie{

    public:
     TrieNode*root;

     Trie(){
        root=new TrieNode('\0');
     }

     void InsertUtil(TrieNode*root,string word){
        // basecase
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }

        // Assumption,word will be in CAPS
        int index=word[0]-'A';
        TrieNode*child;

        if(root->children[index]!=NULL){
            // present
            child=root->children[index];
        }
        else{
            // absent
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        // recursion
        InsertUtil(child,word.substr(1));

     }

     void insertWord(string word){
        InsertUtil(root,word);
     }
     bool searchUtil(TrieNode*root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }


        int index=word[0]-'A';
        TrieNode*child;

        if(root->children[index]!=NULL){
            // present
            child=root->children[index];
        }
        else{
            // absent
          return false;
        }
        return searchUtil(child,word.substr(1));
     }

     bool search(string word){
        return false;
     }

     bool searchWord(string word){
        return searchUtil(root,word);
     }
};

int main(){

    Trie *t=new Trie();
    t->insertWord("ARM");
      t->insertWord("DO");
        t->insertWord("TIME");
    cout<<"Present or not:"<<t->searchWord("TIM")<<endl;


    return 0;

}