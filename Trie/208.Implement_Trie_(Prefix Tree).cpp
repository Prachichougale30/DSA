#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;

        for(int i=0;i<word.length();i++){
            int index = word[i] - 'a';

            if(node->children[index] == NULL){
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;

        for(int i=0;i<word.length();i++){
            int index = word[i] - 'a';

            if(node->children[index] == NULL){
                return false;
            }

            node = node->children[index];
        }

        return node->isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;

        for(int i=0;i<prefix.length();i++){
            int index = prefix[i] - 'a';

            if(node->children[index] == NULL){
                return false;
            }

            node = node->children[index];
        }

        return true;
    }
};