#ifndef C208_TRIE_H
#define C208_TRIE_H

#include <string>

using namespace std;

class TrieNode{
    private:


    public:
        TrieNode *arr[26];
        int end;
        TrieNode();
        ~TrieNode();
};

class c208_Trie
{
    public:
        c208_Trie();
        virtual ~c208_Trie();
        void insert(string word);
        bool search(string word);
        bool startsWith(string prefix);
        void test();

    protected:

    private:
        TrieNode head;
};

#endif // C208_TRIE_H
