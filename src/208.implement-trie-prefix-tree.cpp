#include <iostream>
#include <string.h>
#include <map>
using namespace std;

/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
class Trie {
private:
    struct Node
    {
        Node *children[26];
        bool word = false;
        Node()
        {
            memset(children, 0, sizeof(children));
        }
        Node* childAt(char a)
        {
            size_t pos = a - 97;
            return children[pos];
        }
        Node* createNodeAt(char a)
        {
            size_t pos = a - 97;
            return children[pos] = new Node;
        }
    };
    Node *m_root;

public:
    /** Initialize your data structure here. */
    Trie() {
        m_root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *currentNode = m_root;
        for (char c : word)
        {
            Node *tmp = currentNode->childAt(c);
            if (tmp)
            {
                currentNode = tmp;
            }
            else
            {
                currentNode = currentNode->createNodeAt(c);
            }
        }
        currentNode->word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *currentNode = m_root;
        for (char c : word)
        {
            currentNode = currentNode->childAt(c);
            if (!currentNode)
                return false;
        }
        return currentNode->word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *currentNode = m_root;
        for (char c : prefix)
        {
            currentNode = currentNode->childAt(c);
            if (!currentNode)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// int main(void)
// {
//     Trie *trie = new Trie();
//     trie->insert("apple");
//     cout << trie->search("apple") << endl; // returns true
//     cout << trie->search("app") << endl;   // returns false
//     cout << trie->startsWith("app") << endl; // returns true
//     trie->insert("app");
//     cout << trie->search("app") << endl; // returns true
//     return 0;
// }
