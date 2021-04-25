#include "c208_Trie.h"

#include <iostream>

TrieNode::TrieNode(){
    for(int i=0; i<sizeof(arr)/sizeof(TrieNode *); ++i){
        arr[i] = nullptr;
    }
    end = 0;
}

TrieNode::~TrieNode()
{
    for(int i=0; i<sizeof(arr)/sizeof(TrieNode *); ++i){
        if(arr[i])
            delete arr[i];
    }
}

c208_Trie::c208_Trie()
{
    //ctor
}

c208_Trie::~c208_Trie()
{
    //dtor
}

/** Initialize your data structure here. */
    Trie()
    {

    }

    /** Inserts a word into the trie. */
    void c208_Trie::insert(string word)
    {
        TrieNode *p = &head;
        for(char c:word){
            if(p->arr[c - 'a'] == nullptr){
                p->arr[c - 'a'] = new TrieNode;
            }
            p = p->arr[c - 'a'];
        }
        p->end = 1;
    }

    /** Returns if the word is in the trie. */
    bool c208_Trie::search(string word)
    {
        TrieNode *p = &head;
        for(char c:word){
            if(p->arr[c-'a'] == nullptr)
                return false;
            p = p->arr[c-'a'];
        }
        return p->end?true:false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool c208_Trie::startsWith(string prefix)
    {
        TrieNode *p = &head;
        for(char c:prefix){
            if(p->arr[c-'a'] == nullptr)
                return false;
            p = p->arr[c-'a'];
        }
        return true;
    }
