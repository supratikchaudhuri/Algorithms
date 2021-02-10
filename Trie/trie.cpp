#include<bits/stdc++.h>
using namespace std;

struct Trie {
    Trie *child[26];
    bool eow; 
};

struct Trie* getNode() {
    Trie *node = new Trie;
    node->eow = false;
    
    for(int i = 0; i < 26; i++) {
        node->child[i] = NULL;
    }
    return node;
}

void insert(Trie *root, string word) {
    Trie *it = root;

    for(char c : word) {
        if(!it->child[c-'a'])
            it->child[c-'a'] = getNode();
        it = it->child[c-'a'];
    }
    it->eow = true;
}

bool search(Trie *root, string word) {
    Trie *it = root;

    for(char ch : word) {
        if(!it->child[ch-'a'])
            return false;
        it = it->child[ch-'a'];
    }
    return (it != NULL && it->eow == true);
}

int main() {
    string words[] = { "the", "a", "there",
                      "answer", "any", "by",
                      "bye", "their", "hero", "heroplane" };
    int n = sizeof(words) / sizeof(words[0]);

    Trie *root = getNode(); 

    for(int i = 0; i < n; i++) {
        insert(root, words[i]);
    }

    search(root, "ani")? cout << "Yes\n" : 
                         cout << "No\n"; 
    search(root, "any")? cout << "Yes\n" : 
                           cout << "No\n";
    return 0;
}