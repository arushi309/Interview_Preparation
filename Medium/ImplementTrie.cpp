/*    Implement Trie (Prefix Tree)   */

/*

    Implement a trie with insert, search, and startsWith methods.

    Example:
    Trie trie = new Trie();

    trie.insert("apple");
    trie.search("apple");   // returns true
    trie.search("app");     // returns false
    trie.startsWith("app"); // returns true
    trie.insert("app");   
    trie.search("app");     // returns true

*/


class Node {
public: 
    bool endOfWord;
    Node* children[26];
    Node()
    {
        endOfWord=false;
        for(int i=0;i<26;i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node* root;
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* root2=root;
        for(int i=0;i<word.length();i++)
        {
            if(root2->children[word[i]-'a']==NULL)
               root2->children[word[i]-'a'] = new Node();
            root2=root2->children[word[i]-'a'];
        }
        root2->endOfWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* root2=root;
        for(int i=0;i<word.length();i++)
        {
            if(root2->children[word[i]-'a']==NULL)
               return false;
            root2=root2->children[word[i]-'a'];
        }
        return (root2->endOfWord);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* root2=root;
        for(int i=0;i<prefix.length();i++)
        {
            if(root2->children[prefix[i]-'a']==NULL)
               return false;
            root2=root2->children[prefix[i]-'a'];
        }
        return true;
    }
};